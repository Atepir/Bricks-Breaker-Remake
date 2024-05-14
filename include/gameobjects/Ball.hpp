#ifndef __BALL_HPP
#define __BALL_HPP

#include <iostream>
#include <cmath>
#include <vector>
#include <thread>

#include "gameobjects/GameObject.hpp"
#include "gameobjects/Brick.hpp"
#include "resources/Constants.hpp"

namespace Resources
{
    class ResourceManager;
}

namespace GameObjects
{
    class Power;
    /**
     * @brief Interface for ball observers
     */
    class IBallObserver
    {
    public:
        virtual void onBallFallen(int pBallId) = 0;

        virtual void onBrickDestroyed(BrickType pBrickType) = 0;
        virtual void onBrickDestroyed(BrickType pBrickType, Point pBrickPosition) = 0;
    };

    /**
     * @brief Represents a ball object
     */
    template <eMapType mapType>
    class Ball : public GameObject
    {
    private:
        int mId;
        BallType mType;
        double mRadius;
        std::vector<std::shared_ptr<IBallObserver>> mObservers;
        std::shared_ptr<Power> mPower;

    public:
        Ball(BallType type, Point point, double radius) : GameObject(point, 30, 30, Vector(0, 2.5), 0, 0), mType(type), mRadius(radius)
        {
            srand(time(0));
            this->texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Ball_Basic);
            this->entityType = GameObjectType::GameObjectBall;

            if (MAP_TYPE == eMapType::Circular)
            {
                this->velocity = Vector(rand() % 3 + 0.5, rand() % 3 + 0.5);
            }
        }
        ~Ball() {}

        BallType getType() const { return mType; }
        double getRadius() const { return mRadius; }
        int getId() const { return mId; }
        void setId(int pId) { mId = pId; }

        void update() override;
        void collide(std::shared_ptr<GameObject> pOther) override;

        void addObserver(std::shared_ptr<IBallObserver> observer)
        {
            mObservers.push_back(observer);
        }

        void notifyObserversBallFallen()
        {
            for (auto observer : mObservers)
            {
                if (observer == nullptr)
                    continue;
                observer->onBallFallen(mId);
            }
        }

        void notifyObserversBrickDestroyed(BrickType pBrickType, Point pBrickPosition)
        {
            for (auto observer : mObservers)
            {
                observer->onBrickDestroyed(pBrickType);
                observer->onBrickDestroyed(pBrickType, pBrickPosition);
            }
        }

        inline void damageBrick(std::shared_ptr<Brick> pBrick)
        {
            int damage = 0;
            switch (pBrick->mType)
            {
            case BrickType::BRICK_BLUE:
                damage = 100;
                break;
            case BrickType::BRICK_GREEN:
                damage = 60;
                break;
            case BrickType::BRICK_VIOLET:
                damage = 40;
                break;
            case BrickType::BRICK_YELLOW:
                damage = 20;
                break;
            case BrickType::BRICK_RED:
                damage = 10;
                break;
            }

            pBrick->mHealth -= damage;

            if (pBrick->mHealth <= 0)
            {
                pBrick->mDeleteFlag = true;
                notifyObserversBrickDestroyed(pBrick->mType, pBrick->getPosition());
            }
        }

        void expand()
        {
            if (this->width >= 60 && this->height >= 60)
            {
                return;
            }
            this->width *= 2;
            this->height *= 2;

            std::thread([this]()
                        {
        std::this_thread::sleep_for(std::chrono::seconds(POWER_TIMEOUT));
        this->width /= 2;
        this->height /= 2; })
                .detach();
        }

        void shrink()
        {
            if (this->width <= 15 && this->height <= 15)
            {
                return;
            }
            this->width /= 2;
            this->height /= 2;

            std::thread([this]()
                        {
        std::this_thread::sleep_for(std::chrono::seconds(POWER_TIMEOUT));
        this->width *= 2;
        this->height *= 2; })
                .detach();
        }
    };
}

#include "resources/ResourceManager.hpp"

#endif // __BALL_HPP
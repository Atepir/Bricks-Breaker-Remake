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
        /**
         * @brief Called when a ball has fallen
         * @param pBallId The id of the ball that has fallen
         */
        virtual void onBallFallen(int pBallId) = 0;

        /**
         * @brief Called when a brick has been destroyed
         * @param pBrickType The type of the brick that has been destroyed
         */
        virtual void onBrickDestroyed(eBrickType pBrickType, Point pBrickPosition) = 0;
    };

    /**
     * @brief Represents a ball object
     */
    template <eMapType mapType>
    class Ball : public GameObject
    {
    private:
        int mId;
        eBallType mType;
        double mRadius;
        std::vector<std::shared_ptr<IBallObserver>> mObservers;
        std::shared_ptr<Power> mPower;
        std::unique_ptr<Sound> mCollisionSound;
        std::unique_ptr<Sound> mFallSound;

    public:
        Ball(eBallType type, Point point, double radius) : GameObject(point, 30, 30, Vector(0, 2.5), 0, 0), mType(type), mRadius(radius)
        {
            srand(time(0));
            this->texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Ball_Basic);
            this->entityType = eGameObjectType::GameObject_Ball;

            if (MAP_TYPE == eMapType::Map_Circular)
            {
                this->velocity = Vector(rand() % 3 + 0.5, rand() % 3 + 0.5);
            }

            mCollisionSound = std::make_unique<Sound>("sound/collision.mp3");
            mFallSound = std::make_unique<Sound>("sound/fall.mp3");
        }
        ~Ball() {}

        eBallType getType() const { return mType; }
        double getRadius() const { return mRadius; }
        int getId() const { return mId; }
        void setId(int pId) { mId = pId; }

        void update() override;
        void collide(std::shared_ptr<GameObject> pOther) override;

        /**
         * @brief Adds an observer to the list of the ball observers
         * @param observer The observer to be added
         */
        inline void addObserver(std::shared_ptr<IBallObserver> observer)
        {
            mObservers.push_back(observer);
        }

        /**
         * @brief Notifies the observers that the ball has fallen
         */
        inline void notifyObserversBallFallen()
        {
            for (auto observer : mObservers)
            {
                if (observer == nullptr)
                    continue;
                observer->onBallFallen(mId);
            }
        }

        /**
         * @brief Notifies the observers that a brick has been destroyed
         * @param pBrickType The type of the brick that has been destroyed
         * @param pBrickPosition The position of the brick that has been destroyed
         */
        inline void notifyObserversBrickDestroyed(eBrickType pBrickType, Point pBrickPosition)
        {
            for (auto observer : mObservers)
            {
                observer->onBrickDestroyed(pBrickType, pBrickPosition);
            }
        }

        /**
         * @brief Damages the brick depending on the type of the brick
         * @param pBrick
         */
        inline void damageBrick(std::shared_ptr<Brick> pBrick)
        {
            int damage = 0;
            switch (pBrick->mType)
            {
            case eBrickType::Brick_Blue:
                damage = 100;
                break;
            case eBrickType::Brick_Green:
                damage = 60;
                break;
            case eBrickType::Brick_Violet:
                damage = 40;
                break;
            case eBrickType::Brick_Yellow:
                damage = 20;
                break;
            case eBrickType::Brick_Red:
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

        /**
         * @brief Expands the ball
         */
        void expand()
        {
            if (this->width >= 60 && this->height >= 60)
            {
                return;
            }
            this->width *= 2;
            this->height *= 2;

            std::thread([this]()
                        { std::this_thread::sleep_for(std::chrono::seconds(POWER_TIMEOUT));
                            this->width /= 2;
                            this->height /= 2; })
                .detach();
        }

        /**
         * @brief Shrinks the ball
         */
        void shrink()
        {
            if (this->width <= 15 && this->height <= 15)
            {
                return;
            }
            this->width /= 2;
            this->height /= 2;

            std::thread([this]()
                        { std::this_thread::sleep_for(std::chrono::seconds(POWER_TIMEOUT));
                            this->width *= 2;
                            this->height *= 2; })
                .detach();
        }
    };
}

#include "resources/ResourceManager.hpp"

#endif // __BALL_HPP
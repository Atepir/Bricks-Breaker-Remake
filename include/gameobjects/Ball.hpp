#ifndef __BALL_HPP
#define __BALL_HPP

#include <iostream>
#include <cmath>
#include <vector>
#include <thread>

#include "gameobjects/GameObject.hpp"
#include "resources/Constants.hpp"

class ResourceManager;

namespace GameObjects
{
    class Brick;
    class Power;
    template <eMapType mapType>
    class Ball;

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
        double mMass;
        std::vector<std::shared_ptr<IBallObserver>> mObservers;
        std::shared_ptr<Power> mPower;

    public:
        Ball(BallType type, Point point, double radius, double mass)
        {
            this->mType = type;
            this->mRadius = radius;
            this->mMass = mass;
            this->texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Ball_Basic);
            this->entityType = GameObjectType::GameObjectBall;
        }
        ~Ball() {}

        BallType getType() const { return mType; }
        double getRadius() const { return mRadius; }
        double getMass() const { return mMass; }
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

        void damageBrick(std::shared_ptr<Brick> pBrick, int pDamage)
        {
            pBrick->mHealth -= pDamage;
            if (pBrick->mHealth <= 0)
            {
                pBrick->mDeleteFlag = true;
                notifyObserversBrickDestroyed(pBrick->mType, pBrick->getPosition());
            }
        }

        void expand();

        void shrink();
    };
}

#include "resources/ResourceManager.hpp"
#include "gameobjects/Brick.hpp"

#endif // __BALL_HPP
#ifndef __BALL_HPP
#define __BALL_HPP

#include <iostream>
#include <cmath>
#include <vector>

#include "gameobjects/GameObject.hpp"
#include "resources/Constants.hpp"

class ResourceManager;

namespace GameObjects
{
    class Brick;
    class Power;

    /**
     * @brief Interface for ball observers
     */
    class IBallObserver
    {
    public:
        virtual void onBallFallen() = 0;
        virtual void onBrickDestroyed(BrickType pBrickType) = 0;
        virtual void onBrickDestroyed(BrickType pBrickType, Point pBrickPosition) = 0;
    };

    /**
     * @brief Represents a ball object
     */
    class Ball : public GameObject
    {
    private:
        BallType mType;
        double mRadius;
        double mMass;
        std::vector<std::shared_ptr<IBallObserver>> mObservers;
        std::shared_ptr<Power> mPower;

    public:
        Ball(BallType type, Point point, double radius, double mass);
        ~Ball();

        void update() override;
        void collide(std::shared_ptr<GameObject> pOther) override;

        void addObserver(std::shared_ptr<IBallObserver> observer);

        BallType getType() const { return mType; }
        double getRadius() const { return mRadius; }
        double getMass() const { return mMass; }

        void setPower(std::shared_ptr<Power> pPower) { mPower = pPower; }
        std::shared_ptr<Power> getPower() { return mPower; }

        void notifyObserversBallFallen();
        void notifyObserversBrickDestroyed(BrickType pBrickType);

        void damageBrick(std::shared_ptr<Brick> pBrick, int pDamage);
    };
}

#include "resources/ResourceManager.hpp"
#include "gameobjects/Brick.hpp"

#endif // __BALL_HPP
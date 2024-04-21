#ifndef __BALL_HPP
#define __BALL_HPP

#include <iostream>
#include <cmath>

#include "gameobjects/GameObject.hpp"
#include "resources/Constants.hpp"

class ResourceManager;

namespace GameObjects
{
    /**
     * @brief Represents a ball object
     */
    class Ball : public GameObject
    {
    private:
        BallType mType;
        double mRadius;
        double mMass;

    public:
        Ball(BallType type, Point point, double radius, double mass);
        ~Ball();

        void update() override;
        void collide(GameObject *pOther) override;
    };
}

#include "resources/ResourceManager.hpp"

#endif // __BALL_HPP
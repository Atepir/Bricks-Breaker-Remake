#ifndef __BRICK_HPP
#define __BRICK_HPP

#include <iostream>

#include "gameobjects/GameObject.hpp"
#include "resources/Enums.hpp"
#include "resources/Constants.hpp"
#include "resources/ResourceManager.hpp"

#define BRICK_WIDTH 140
#define BRICK_HEIGHT 50

namespace GameObjects
{
    class Ball;
    class Brick : public GameObject
    {
        friend class Ball;

    private:
        BrickType mType;
        int mHealth;
        bool mDeleteFlag = false;

    public:
        Brick(Point position, double width, double height, BrickType type, int health);
        ~Brick();

        void update() override;
        void collide(std::shared_ptr<GameObject> pOther) override;

        bool getDeleteFlag() { return mDeleteFlag; }
    };
}

#endif // __BRICK_HPP
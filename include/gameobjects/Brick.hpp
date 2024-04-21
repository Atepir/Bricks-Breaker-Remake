#ifndef __BRICK_HPP
#define __BRICK_HPP

#include <iostream>

#include "gameobjects/GameObject.hpp"
#include "resources/Enums.hpp"
#include "resources/Constants.hpp"
#include "resources/ResourceManager.hpp"

#define BRICK_WIDTH 140
#define BRICK_HEIGHT 48

namespace GameObjects
{
    class Brick : public GameObject
    {
    private:
        BrickType mType;
        int mHealth;

    public:
        Brick(Point position, double width, double height, BrickType type, int health);
        ~Brick();

        void update() override;
        void collide(GameObject *pOther) override;
    };
}

#endif // __BRICK_HPP
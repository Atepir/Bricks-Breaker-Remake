#ifndef __BRICK_HPP
#define __BRICK_HPP

#include <iostream>

#include "gameobjects/GameObject.hpp"
#include "resources/Enums.hpp"
#include "resources/Constants.hpp"
#include "resources/ResourceManager.hpp"

#define BRICK_WIDTH 118
#define BRICK_HEIGHT 50

namespace GameObjects
{
    template<eMapType mapType>
    class Ball;

    class Brick : public GameObject
    {
        template<eMapType mapType> 
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

#include "gameobjects/Ball.hpp"

#endif // __BRICK_HPP
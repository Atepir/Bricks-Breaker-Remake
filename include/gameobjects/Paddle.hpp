#ifndef __PADDLE_HPP
#define __PADDLE_HPP

#include <iostream>
#include <cmath>

#include "gameobjects/GameObject.hpp"
#include "resources/Enums.hpp"
#include "resources/Constants.hpp"

class ResourceManager;

#define ROTATION_SPEED_MULTIPLIER 200

template <eMapType mapType>
class Paddle : public GameObject
{
private:
    static inline Paddle *instance = nullptr;

public:
    Paddle(Point position, Vector velocity, double width, double height, double angle, double angularVelocity) : GameObject(position, width, height, velocity, angle, angularVelocity, nullptr)
    {
        switch (mapType)
        {
        case eMapType::Basic:
            pTexture = ResourceManager::getInstance()->getTexture("paddle_basic");
            break;
        case eMapType::Circular:
            pTexture = ResourceManager::getInstance()->getTexture("paddle_circular");
            break;
        }

        this->entityType = GameObjectType::GameObjectPaddle;
    }

    ~Paddle() {}

    Paddle(const Paddle &) = delete;
    Paddle &operator=(const Paddle &) = delete;

    static Paddle *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Paddle<eMapType::Basic>(Point(120, 600), Vector(30, 30), 140, 40, 0, 0);
        }
        return instance;
    }

    void update() override;

    void collide(GameObject *other) override
    {
    }
};

#include "resources/ResourceManager.hpp"

#endif // __PADDLE_HPP

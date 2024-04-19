#ifndef __PADDLE_HPP
#define __PADDLE_HPP

#include <iostream>
#include <cmath>

#include "gameobjects/GameObject.hpp"
#include "resources/Enums.hpp"
#include "resources/Constants.hpp"

template <eMapType mapType>
class GraphicsManager;
class ResourceManager;

#define ROTATION_SPEED_MULTIPLIER 200

template <eMapType mapType>
class Paddle : public GameObject
{
private:
    static inline Paddle *instance = nullptr;

public:
    Paddle(Point position, double width, double height, Vector velocity, double angularVelocity)
        : GameObject(position, velocity, angle, angularVelocity, ResourceManager::getInstance()->getTexture("paddle"))
    {
        entityType = GameObjectType::GameObjectPaddle;
    }

    ~Paddle() {}

    Paddle(const Paddle &) = delete;
    Paddle &operator=(const Paddle &) = delete;

    static Paddle *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Paddle(Point(420, 600), 160, 60, Vector(30, 30), 10);
        }
        return instance;
    }

    void update() override;

    void draw() override
    {
        SDL_Rect dstRect = {(int)position.x - 80, (int)position.y - 20, (int)width, (int)height};
        SDL_RenderCopyEx(GraphicsManager<MAP_TYPE>::getInstance()->getRenderer(), pTexture, NULL, &dstRect, angle, NULL, SDL_FLIP_NONE);
    }

    void collide(GameObject *other) override
    {
    }
};

#include "graphics/GraphicsManager.hpp"
#include "resources/ResourceManager.hpp"

#endif // __PADDLE_HPP

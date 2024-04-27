#ifndef __PADDLE_HPP
#define __PADDLE_HPP

#include <iostream>
#include <cmath>

#include "gameobjects/GameObject.hpp"
#include "resources/Enums.hpp"
#include "resources/Constants.hpp"
#include "resources/ResourceManager.hpp"

#define ROTATION_SPEED_MULTIPLIER 200

namespace GameObjects
{
    template <eMapType mapType>
    class Paddle : public GameObject
    {
    private:
        static inline std::shared_ptr<Paddle> pInstance = nullptr;

    public:
        Paddle(Point position, Vector velocity, double width, double height, double angle, double angularVelocity) : GameObject(position, width, height, velocity, angle, angularVelocity)
        {
            switch (mapType)
            {
            case eMapType::Basic:
                texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Paddle_Basic);
                std::cout << "Paddle texture: " << texture->getTexture() << std::endl;
                break;
            case eMapType::Circular:
                texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Paddle_Circular);
                break;
            }

            this->entityType = GameObjectType::GameObjectPaddle;
        }

        ~Paddle() {}

        Paddle(const Paddle &) = delete;
        Paddle &operator=(const Paddle &) = delete;

        static std::shared_ptr<Paddle> getInstance()
        {
            if (pInstance == nullptr)
            {
                pInstance = std::make_shared<Paddle>(Point(120, 600), Vector(30, 30), 140, 40, 0, 0);
            }
            return pInstance;
        }

        void update() override;

        void collide(std::shared_ptr<GameObject> pOther) override
        {
        }
    };
}
#endif // __PADDLE_HPP

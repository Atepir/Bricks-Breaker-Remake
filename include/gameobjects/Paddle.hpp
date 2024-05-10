#ifndef __PADDLE_HPP
#define __PADDLE_HPP

#include <iostream>
#include <cmath>
#include <thread>

#include "gameobjects/GameObject.hpp"
#include "resources/Enums.hpp"
#include "resources/Constants.hpp"
#include "resources/ResourceManager.hpp"
#include "gameobjects/Power.hpp"

#define ROTATION_SPEED_MULTIPLIER 200

namespace GameObjects
{
    template <eMapType mapType>
    class Paddle : public GameObject, public GameObjects::IPowerObserver
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
                pInstance = std::make_shared<Paddle>(Point(420, 620), Vector(30, 30), 140, 40, 0, 0);
            }
            return pInstance;
        }

        void update() override;

        void collide(std::shared_ptr<GameObject> pOther) override
        {
        }

        void onPaddleCollide(PowerType pPowerType) override
        {
            switch (pPowerType)
            {
            case PowerType::POWERDOWN_SHRINK_PADDLE:
                width = 70;
                texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Paddle_Basic_Small);
                std::thread([this]()
                            { 
                                std::this_thread::sleep_for(std::chrono::seconds(POWER_TIMEOUT)); 
                                width = 140;
                                texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Paddle_Basic); })
                    .detach();
                break;
            case PowerType::POWERUP_EXPAND_PADDLE:
                width = 210;
                texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Paddle_Basic_Large);

                std::thread([this]()
                            { 
                                std::this_thread::sleep_for(std::chrono::seconds(POWER_TIMEOUT)); 
                                width = 140;
                                texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Paddle_Basic); })
                    .detach();
                break;
            default:
                break;
            }
        }
    };
}
#endif // __PADDLE_HPP

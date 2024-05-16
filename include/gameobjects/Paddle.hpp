#ifndef __PADDLE_HPP
#define __PADDLE_HPP

#include <iostream>
#include <cmath>
#include <thread>

#include "resources/Enums.hpp"
#include "resources/Constants.hpp"
#include "resources/ResourceManager.hpp"

#include "gameobjects/GameObject.hpp"
#include "gameobjects/Power.hpp"

#include "gui/EventListener.hpp"

#define ROTATION_SPEED_MULTIPLIER 200

namespace GameObjects
{
    /**
     * @brief Represents a paddle object
     */
    template <eMapType mapType>
    class Paddle : public GameObject, public GameObjects::IPowerObserver, public Gui::IMoveListener
    {
    private:
        static inline std::shared_ptr<Paddle> pInstance = nullptr;

    public:
        Paddle(Point position, Vector velocity, double width, double height, double angle, double angularVelocity) : GameObject(position, width, height, velocity, angle, angularVelocity)
        {
            switch (mapType)
            {
            case eMapType::Map_Basic:
                texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Paddle_Basic);
                break;
            case eMapType::Map_Circular:
                texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Paddle_Circular);
                this->width = 70;
                this->height = 20;
                break;
            }

            this->entityType = eGameObjectType::GameObject_Paddle;
        }

        ~Paddle() {}

        Paddle(const Paddle &) = delete;
        Paddle &operator=(const Paddle &) = delete;

        static std::shared_ptr<Paddle> getInstance()
        {
            if (pInstance == nullptr)
            {
                pInstance = std::make_shared<Paddle>(Point(420, 620), Vector(20, 0), 140, 40, 0, 5);
            }
            return pInstance;
        }

        void resetPaddle()
        {
            position = Point(420, 620);
            velocity = Vector(20, 0);
            angle = 0;
            angularVelocity = 5;
        }

        void update() override;

        /**
         * @brief Handles the collision of the paddle with a power
         * @param pPowerType The type of the power that the paddle collided with
         */
        void onPaddleCollide(ePowerType pPowerType) override
        {
            if (mapType == eMapType::Map_Circular)
            {
                return;
            }
            switch (pPowerType)
            {
            case ePowerType::PowerDown_Shrink_Paddle:
                width = 70;
                texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Paddle_Basic_Small);
                std::thread([this]()
                            { 
                                std::this_thread::sleep_for(std::chrono::seconds(POWER_TIMEOUT)); 
                                width = 140;
                                texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Paddle_Basic); })
                    .detach();
                break;
            case ePowerType::PowerUp_Expand_Paddle:
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

        void handleMouseMove(bool right);
        void keyDownLeft();
        void keyDownRight();
    };
}
#endif // __PADDLE_HPP

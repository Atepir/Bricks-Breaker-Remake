#ifndef __POWER_HPP
#define __POWER_HPP

#include <iostream>
#include <cmath>
#include <vector>

#include "gameobjects/GameObject.hpp"
#include "resources/Enums.hpp"
#include "resources/Constants.hpp"
#include "resources/ResourceManager.hpp"

class ResourceManager;

namespace GameObjects
{
    template <eMapType mapType>
    class Ball;

    /**
     * @brief Interface for power observers
     */
    class IPowerObserver
    {
    public:
        /**
         * @brief Called when a power object collides with a paddle
         *
         * @param pPowerType
         */
        virtual void onPaddleCollide(ePowerType pPowerType) = 0;
    };

    /**
     * @brief Represents a power object
     */

    class Power : public GameObject
    {
    private:
        ePowerType mPowerType;
        bool mDeleteFlag = false;
        std::vector<std::shared_ptr<IPowerObserver>> mPowerObservers;

        void notifyObserversPaddleCollided();

    public:
        Power(ePowerType type, Point point);
        ~Power() {}

        void update();
        void collide(std::shared_ptr<GameObject> pOther);

        ePowerType getType() const { return mPowerType; }

        void addObserver(std::shared_ptr<IPowerObserver> pPowerObserver);

        bool getDeleteFlag() const { return mDeleteFlag; }
    };
}

#include "resources/ResourceManager.hpp"

#endif // __POWER_HPP
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

    class IPowerObserver 
    {
        public:
            virtual void onPaddleCollide(PowerType pPowerType) = 0;
    };

    /**
     * @brief Represents a power object
     */

    class Power : public GameObject
    {
    private:
		PowerType mPowerType;
        bool mDeleteFlag = false;
        std::vector<std::shared_ptr<IPowerObserver>> mPowerObservers;

    public:
        Power(PowerType type, Point point);
        ~Power() {}

        void update();
        void collide(std::shared_ptr<GameObject> pOther);
        
        PowerType getType() const { return mPowerType; }

        void addObserver(std::shared_ptr<IPowerObserver> pPowerObserver);

        void notifyObserversPaddleCollided();

        bool getDeleteFlag() { return mDeleteFlag; }
    };
}
#endif // __POWER_HPP
#include "resources/ResourceManager.hpp"
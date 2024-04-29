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
    class Ball;
    class Paddle;

    /**
     * @brief Interface for power observers
     */
    class IPowerObserver
    {
    public:
        virtual void onPowerFallen() = 0;
    };

    /**
     * @brief Represents a power object
     */

    // Classe abstraite power qui hérite de GameObject
    class Power : public GameObject
    {
    protected:
		PowerType mType;
		double mLength;
		double mMass;
		std::vector<std::shared_ptr<IPowerObserver>> mObservers;

    public:
        Power(PowerType type, Point point, double length, double mass);
        virtual ~Power() {}

        // DEBUG
        virtual void description() = 0;

        virtual void update() = 0;
        virtual void collide(std::shared_ptr<GameObject> pOther) = 0;
        virtual void addObserver(std::shared_ptr<IPowerObserver> observer) = 0;
        
        PowerType getType() const { return mType; }
        double getLength() const { return mLength; }
        double getMass() const { return mMass; }

        void notifyObserversPowerFallen();


    };

    class PowerExtendBall : public Power
    {
    public:
		PowerExtendBall(Point point, double length, double mass);
		~PowerExtendBall() {}

		void description() override;
		void update() override;
		void collide(std::shared_ptr<GameObject> pOther) override;
        void addObserver(std::shared_ptr<IPowerObserver> observer) override;
	};

    class PowerShrinkBall : public Power
    {
    public:
        PowerShrinkBall(Point point, double length, double mass);
        ~PowerShrinkBall() {}

        void description() override;
        void update() override;
        void collide(std::shared_ptr<GameObject> pOther) override;
        void addObserver(std::shared_ptr<IPowerObserver> observer) override;
    };

    class PowerExtendPaddle : public Power
	{
    public:
        PowerExtendPaddle(Point point, double length, double mass);
		~PowerExtendPaddle() {}

		void description() override;
		void update() override;
		void collide(std::shared_ptr<GameObject> pOther) override;
        void addObserver(std::shared_ptr<IPowerObserver> observer) override;
    };

    class PowerShrinkPaddle : public Power
    {
    public:
		PowerShrinkPaddle(Point point, double length, double mass);
		~PowerShrinkPaddle() {}

		void description() override;
		void update() override;
		void collide(std::shared_ptr<GameObject> pOther) override;
        void addObserver(std::shared_ptr<IPowerObserver> observer) override;
	};

    class PowerExtraLife : public Power
    {
    public:
        PowerExtraLife(Point point, double length, double mass);
        ~PowerExtraLife() {}
           
        void description() override;
        void update() override;
        void collide(std::shared_ptr<GameObject> pOther) override;
        void addObserver(std::shared_ptr<IPowerObserver> observer) override;
    };

    class PowerFireBall : public Power
    {
    public:
        PowerFireBall(Point point, double length, double mass);
		~PowerFireBall() {}

		void description() override;
		void update() override;
		void collide(std::shared_ptr<GameObject> pOther) override;
        void addObserver(std::shared_ptr<IPowerObserver> observer) override;
	};

}
#endif // __POWER_HPP
#include "resources/ResourceManager.hpp"
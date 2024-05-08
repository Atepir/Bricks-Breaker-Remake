#ifndef __POWER_FACTORY_HPP
#define __POWER_FACTORY_HPP


#include "gameobjects/Power.hpp"
#include "gameobjects/Ball.hpp"
#include "geometry/Dimensions.hpp"

namespace Factories
{
    class PowerFactory : public GameObjects::IBallObserver
    {
	public:
		PowerFactory() = default;
		virtual ~PowerFactory() = default;

		static std::shared_ptr<GameObjects::Power> createPower(PowerType pType, Point pPowerPosition);

		void onBallFallen() override
		{
		}

		void onBrickDestroyed(BrickType pBrickType) override
		{
		}
		void onBrickDestroyed(BrickType pBrickType, Point pBrickPosition) override;
	};
}   

#endif // __POWER_FACTORY_HPP
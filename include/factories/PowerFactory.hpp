#ifndef __POWER_FACTORY_HPP
#define __POWER_FACTORY_HPP

#include <cstdlib>  

#include "gameobjects/gameobject.hpp"
#include "gameobjects/Power.hpp"
#include "gameobjects/Ball.hpp"
#include "geometry/Dimensions.hpp"

namespace Factories
{
    class PowerFactory : public GameObjects::IBallObserver
    {
	private:
		std::vector <std::shared_ptr<GameObjects::Power>> mPowers;

	public:
		PowerFactory() = default;
		virtual ~PowerFactory() = default;

		void createPower(PowerType pType, Point pPowerPosition);

		void onBallFallen() override
		{
		}

		void onBrickDestroyed(BrickType pBrickType) override
		{
		}
		void onBrickDestroyed(BrickType pBrickType, Point pBrickPosition) override;

		void update();
		void render(Graphics::Renderer &pRenderer);
		void collide(std::shared_ptr<GameObjects::GameObject> pGameObject);
	};
}   

#endif // __POWER_FACTORY_HPP
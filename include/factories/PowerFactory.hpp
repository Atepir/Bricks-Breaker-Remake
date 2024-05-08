#ifndef __POWER_FACTORY_HPP
#define __POWER_FACTORY_HPP

#include <cstdlib>

#include "gameobjects/gameobject.hpp"
#include "gameobjects/Power.hpp"
#include "gameobjects/Ball.hpp"
#include "geometry/Dimensions.hpp"
#include "factories/BallFactory.hpp"

namespace Factories
{
	class PowerFactory : public GameObjects::IBallObserver
	{
	private:
		std::vector<std::shared_ptr<GameObjects::Power>> mPowers;
		static inline std::shared_ptr<PowerFactory> pInstance = nullptr;

	public:
		PowerFactory() = default;
		virtual ~PowerFactory() = default;

		PowerFactory(const PowerFactory &) = delete;
		PowerFactory &operator=(const PowerFactory &) = delete;

		static std::shared_ptr<PowerFactory> getInstance()
		{
			if (pInstance == nullptr)
			{
				pInstance = std::make_shared<PowerFactory>();
			}
			return pInstance;
		}

		void resetPowers()
		{
			mPowers.clear();
		}

		void createPower(PowerType pType, Point pPowerPosition);

		void onBallFallen(int pBallId) override {}

		void onBrickDestroyed(BrickType pBrickType) override {}
		void onBrickDestroyed(BrickType pBrickType, Point pBrickPosition) override;

		void update();
		void render(Graphics::Renderer &pRenderer);
		void collide(std::shared_ptr<GameObjects::GameObject> pGameObject);
	};
}

#endif // __POWER_FACTORY_HPP
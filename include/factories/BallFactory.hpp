#ifndef __BALL_FACTORY_HPP
#define __BALL_FACTORY_HPP

#include "gameobjects/Ball.hpp"
#include "gameobjects/GameObject.hpp"
#include "geometry/Dimensions.hpp"
#include "gameobjects/Power.hpp"

namespace Factories
{
    class BallFactory : public GameObjects::IPowerObserver, public GameObjects::IBallObserver
    {
    private:
        static inline std::shared_ptr<BallFactory> pInstance = nullptr;
        std::vector<std::shared_ptr<GameObjects::Ball>> mBalls;
        

    public:
        BallFactory() = default;
        virtual ~BallFactory() = default;

        BallFactory(const BallFactory&) = delete;
        BallFactory& operator=(const BallFactory&) = delete;

        static std::shared_ptr<BallFactory> getInstance() {
            if (pInstance == nullptr) {
                pInstance = std::make_shared<BallFactory>();
            }
            return pInstance;
        }

        void createBall(BallType pType);
        void destroyBall(std::shared_ptr<GameObjects::Ball> pBall);

        void update();
		void render(Graphics::Renderer &pRenderer);
        void collide(std::shared_ptr<GameObjects::GameObject> pOther);

        void addObserver(std::shared_ptr<GameObjects::IBallObserver> observer);

        void onPaddleCollide(PowerType pPowerType) override;

        int getBallCount() const { return mBalls.size(); }

        void onBallFallen() override {};
        void onBallFallen(std::shared_ptr<GameObjects::Ball> pBall) override;

		void onBrickDestroyed(BrickType pBrickType) override{}
		void onBrickDestroyed(BrickType pBrickType, Point pBrickPosition) override {}
    };
}

#endif // __BALL_FACTORY_HPP

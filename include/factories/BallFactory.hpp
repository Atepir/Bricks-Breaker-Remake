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
        std::vector<std::shared_ptr<GameObjects::Ball<MAP_TYPE>>> mBalls;
        std::vector<std::shared_ptr<GameObjects::IBallObserver>> mBallObservers;
        int mLastGeneratedBallId = 0;

    public:
        BallFactory() = default;
        virtual ~BallFactory()
        {
            for (auto &ball : mBalls)
            {
                ball.reset();
            }
        }

        BallFactory(const BallFactory &) = delete;
        BallFactory &operator=(const BallFactory &) = delete;

        static std::shared_ptr<BallFactory> getInstance()
        {
            if (pInstance == nullptr)
            {
                pInstance = std::make_shared<BallFactory>();
            }
            return pInstance;
        }

        void resetBalls()
        {
            mBalls.clear();
            mBallObservers.clear();
        }

        void createBall(BallType pType);
        void destroyBall(int pBallId);

        void update();
        void render(Graphics::Renderer &pRenderer);
        void collide(std::shared_ptr<GameObjects::GameObject> pOther);

        void addObserver(std::shared_ptr<GameObjects::IBallObserver> observer);

        void onPaddleCollide(PowerType pPowerType) override;

        int getBallCount() const { return mBalls.size(); }

        void onBallFallen(int pBallId) override;

        void onBrickDestroyed(BrickType pBrickType) override {}
        void onBrickDestroyed(BrickType pBrickType, Point pBrickPosition) override {}
    };
}

#endif // __BALL_FACTORY_HPP

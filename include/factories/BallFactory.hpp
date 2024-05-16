#ifndef __BALL_FACTORY_HPP
#define __BALL_FACTORY_HPP

#include "gameobjects/Ball.hpp"
#include "gameobjects/GameObject.hpp"
#include "gameobjects/Power.hpp"

namespace Factories
{
    /**
     * @brief Factory class for creating balls
     */
    class BallFactory : public GameObjects::IPowerObserver, public GameObjects::IBallObserver
    {
    private:
        static inline std::shared_ptr<BallFactory> pInstance = nullptr;
        std::vector<std::shared_ptr<GameObjects::Ball<MAP_TYPE>>> mBalls;

        /**
         * @brief List of objects observing the balls
         */
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

        /**
         * @brief Reset the balls
         */
        void resetBalls()
        {
            mBalls.clear();
            mBallObservers.clear();
        }

        /**
         * @brief Create a ball of the given type and add it to the list of balls
         * @param pType The type of the ball to be created
         */
        void createBall(eBallType pType);

        /**
         * @brief Destroy the ball with the given id and remove it from the list of balls
         * @param pBallId The id of the ball to be destroyed
         */
        void destroyBall(int pBallId);

        void update();
        void render(Graphics::Renderer &pRenderer);
        void collide(std::shared_ptr<GameObjects::GameObject> pOther);

        /**
         * @brief Add an observer to the ball factory
         * @param observer The observer to be added
         */
        void addObserver(std::shared_ptr<GameObjects::IBallObserver> observer);

        void onPaddleCollide(ePowerType pPowerType) override;

        int getBallCount() const { return mBalls.size(); }

        /**
         * @brief Callback for when a ball has fallen
         * @param pBallId The id of the ball that has fallen
         */
        void onBallFallen(int pBallId) override;

        void onBrickDestroyed(eBrickType pBrickType, Point pBrickPosition) override {}
    };
}

#endif // __BALL_FACTORY_HPP

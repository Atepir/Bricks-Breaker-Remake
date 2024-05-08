#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#include "gameobjects/Ball.hpp"

#include <iostream>
#include <string>

#define DEFAULT_LIVES 3

namespace Core
{
    class Player : public GameObjects::IBallObserver
    {
    private:
        int mScore;
        int mLives;
        std::string mName;

    public:
        Player() : mScore(0), mLives(DEFAULT_LIVES), mName("Player") {}
        ~Player() = default;

        void setScore(int pScore) { mScore = pScore; }
        void setLives(int pLives) { mLives = pLives; }
        void setName(std::string pName) { mName = pName; }

        int getScore() const { return mScore; }
        int getLives() const { return mLives; }
        std::string getName() const { return mName; }

        void addScore(int pScore) { mScore += pScore; }
        void removeLife() { mLives--; }

        void onBallFallen() override
        {
            if (Factories::BallFactory::getInstance()->getBallCount() == 1)
                removeLife();
        }
        void onBallFallen(std::shared_ptr<GameObjects::Ball> pBall) override {}

        void onBrickDestroyed(BrickType pBrickType) override
        {
            switch (pBrickType)
            {
            case BrickType::BRICK_BLUE:
                addScore(10);
                break;
            case BrickType::BRICK_GREEN:
                addScore(20);
                break;
            case BrickType::BRICK_VIOLET:
                addScore(50);
                break;
            case BrickType::BRICK_YELLOW:
                addScore(100);
                break;
            case BrickType::BRICK_RED:
                addScore(200);
                break;
            default:
                break;
            }
        }

        void onBrickDestroyed(BrickType pBrickType, Point pBrickPosition) override {}


        friend std::ostream &operator<<(std::ostream &os, Player player)
        {
            os << "Player: " << player.getName() << " Score: " << player.getScore() << " Lives: " << player.getLives();
            return os;
        };
    };
}

#endif
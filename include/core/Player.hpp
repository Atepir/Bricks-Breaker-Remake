#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#include "gameobjects/Ball.hpp"
#include "gameobjects/Power.hpp"

#include <iostream>
#include <string>

#define DEFAULT_LIVES 5

namespace Core
{
    /**
     * @brief Represents a player in the game
     * @details A player has a score, lives and a name and can observe the ball and power objects
     */
    class Player : public GameObjects::IBallObserver, public GameObjects::IPowerObserver
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

        void onBallFallen(int pBallId) override
        {
            if (Factories::BallFactory::getInstance()->getBallCount() == 1)
                removeLife();
        }

        void onBrickDestroyed(eBrickType pBrickType, Point pBrickPosition) override
        {
            switch (pBrickType)
            {
            case eBrickType::Brick_Blue:
                addScore(10);
                break;
            case eBrickType::Brick_Green:
                addScore(20);
                break;
            case eBrickType::Brick_Violet:
                addScore(50);
                break;
            case eBrickType::Brick_Yellow:
                addScore(100);
                break;
            case eBrickType::Brick_Red:
                addScore(200);
                break;
            default:
                break;
            }
        }

        friend std::ostream &operator<<(std::ostream &os, Player player)
        {
            os << "Player: " << player.getName() << " Score: " << player.getScore() << " Lives: " << player.getLives();
            return os;
        };

        void onPaddleCollide(ePowerType pPowerType) override
        {
            switch (pPowerType)
            {
            case ePowerType::PowerUp_Extra_Life:
                mLives++;
                addScore(100);
                break;
            case ePowerType::PowerUp_Expand_Ball:
                addScore(50);
                break;
            case ePowerType::PowerDown_Shrink_Ball:
                addScore(-50);
                break;
            case ePowerType::PowerUp_Expand_Paddle:
                addScore(50);
                break;
            case ePowerType::PowerDown_Shrink_Paddle:
                addScore(-50);
                break;
            case ePowerType::PowerUp_Multi_Ball:
                addScore(100);
                break;
            default:
                break;
            }
        }
    };
}

#endif
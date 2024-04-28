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
            removeLife();
        }

        void onBrickDestroyed(BrickType pBrickType) override
        {
            switch (pBrickType)
            {
            case BrickType::NORMAL:
                addScore(10);
                break;
            case BrickType::UNBREAKABLE:
                addScore(20);
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
    };
}

#endif
#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#include <iostream>
#include <string>

#define DEFAULT_LIVES 3

namespace Core
{
    class Player
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

        friend std::ostream &operator<<(std::ostream &os, Player player)
        {
            os << "Player: " << player.getName() << " Score: " << player.getScore() << " Lives: " << player.getLives();
            return os;
        };
    };
}

#endif
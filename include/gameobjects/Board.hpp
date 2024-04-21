#ifndef __BOARD_HPP
#define __BOARD_HPP

#include <iostream>
#include <vector>

#include "resources/Enums.hpp"
#include "gameobjects/GameObject.hpp"
#include "gameobjects/Brick.hpp"

#define BOARD_PADDING 72

namespace GameObjects
{
    template <eMapType mapType>
    class Board : public GameObject
    {
    private:
        std::vector<Brick *> mBricks;

        static inline Board *pInstance = nullptr;

    public:
        Board();
        ~Board()
        {
            for (auto brick : mBricks)
            {
                delete brick;
            }
        }

        Board(const Board &) = delete;
        Board &operator=(const Board &) = delete;

        static Board *getInstance()
        {
            if (pInstance == nullptr)
            {
                pInstance = new Board();
            }
            return pInstance;
        }

        std::vector<Brick *> getBricks() { return mBricks; }

        void update() override
        {
            for (auto brick : mBricks)
            {
                brick->update();
            }
        }

        void collide(GameObject *pOther) override {}
    };
}

#endif // __BOARD_HPP
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
        std::vector<std::shared_ptr<Brick>> mBricks;

        static inline std::shared_ptr<Board> pInstance = nullptr;

    public:
        Board();
        ~Board()
        {
            for (auto brick : mBricks)
            {
                brick.reset();
            }
        }

        Board(const Board &) = delete;
        Board &operator=(const Board &) = delete;

        static std::shared_ptr<Board> getInstance()
        {
            if (pInstance == nullptr)
            {
                pInstance = std::make_shared<Board>();
            }
            return pInstance;
        }

        std::vector<std::shared_ptr<Brick>> getBricks() { return mBricks; }

        void update() override
        {
            for (auto brick : mBricks)
            {
                brick->update();
            }
        }

        void collide(std::shared_ptr<GameObject> pOther) override {}
    };
}

#endif // __BOARD_HPP
#ifndef __BOARD_HPP
#define __BOARD_HPP

#include <iostream>
#include <fstream>
#include <vector>

#include "resources/Enums.hpp"
#include "resources/LevelManager.hpp"
#include "gameobjects/GameObject.hpp"
#include "gameobjects/Brick.hpp"

#define BOARD_PADDING 40
#define MARGIN_TOP 80
#define INITIAL_BRICK_HEALTH 100

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

        void fillBasicBoard(std::string pPath);
        void fillCircularBoard();
        void reset();

        bool isFinished()
        {
            return mBricks.size() <= 0;
        }

        std::vector<std::shared_ptr<Brick>> getBricks() { return mBricks; }

        void update() override
        {
            for (auto brick : mBricks)
            {
                if (brick == nullptr)
                {
                    continue;
                }
                brick->update();
                if (brick->getDeleteFlag())
                {
                    std::cout << "delete flag: " << brick->getDeleteFlag() << std::endl;
                    std::cout << "Brick deleted" << std::endl;
                    mBricks.erase(std::remove(mBricks.begin(), mBricks.end(), brick), mBricks.end());
                }
            }
        }

        void collide(std::shared_ptr<GameObject> pOther) override {}
    };
}

#endif // __BOARD_HPP
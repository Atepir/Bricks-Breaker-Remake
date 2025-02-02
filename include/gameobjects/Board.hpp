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
    /**
     * @brief Represents a board that is a collection of bricks
     */
    template <eMapType mapType>
    class Board : public GameObject
    {
    private:
        std::vector<std::shared_ptr<Brick>> mBricks;

        static inline std::shared_ptr<Board> pInstance = nullptr;

        void fillBasicBoard(std::string pPath);
        void fillCircularBoard(std::string pPath);

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

        void reset();

        /**
         * @brief Either or not the current level is finished
         * @return true
         * @return false
         */
        inline bool isFinished()
        {
            return mBricks.size() <= 0;
        }

        inline std::vector<std::shared_ptr<Brick>> getBricks() { return mBricks; }

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
                    mBricks.erase(std::remove(mBricks.begin(), mBricks.end(), brick), mBricks.end());
                }
            }
        }
    };
}

#endif // __BOARD_HPP
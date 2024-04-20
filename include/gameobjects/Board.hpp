#ifndef __BOARD_HPP
#define __BOARD_HPP

#include <iostream>
#include <vector>

#include "resources/Enums.hpp"
#include "gameobjects/GameObject.hpp"
#include "gameobjects/Brick.hpp"

#define BOARD_PADDING 72

template <eMapType mapType>
class Board : public GameObject
{
private:
    std::vector<Brick *> bricks;

    static inline Board *instance = nullptr;

public:
    Board();
    ~Board()
    {
        for (auto brick : bricks)
        {
            delete brick;
        }
    }

    Board(const Board &) = delete;
    Board &operator=(const Board &) = delete;

    static Board *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Board();
        }
        return instance;
    }

    std::vector<Brick *> getBricks() { return bricks; }

    void update() override
    {
        for (auto brick : bricks)
        {
            brick->update();
        }
    }

    void collide(GameObject *other) override {}
};

#endif // __BOARD_HPP
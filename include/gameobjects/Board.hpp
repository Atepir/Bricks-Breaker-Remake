#ifndef __BOARD_HPP
#define __BOARD_HPP

#include <iostream>
#include <vector>

#include "resources/Enums.hpp"
#include "gameobjects/GameObject.hpp"
#include "gameobjects/Brick.hpp"

#define PADDING 72

class Board : public GameObject
{
private:
    std::vector<Brick *> bricks;
    eMapType mapType;

    static Board *instance;

public:
    Board(eMapType pMapType);
    ~Board();
    void update();
    void draw();
    void collide(GameObject *other);

    Board(const Board &) = delete;
    Board &operator=(const Board &) = delete;

    static Board *getInstance(eMapType mapType);
};

#endif // __BOARD_HPP
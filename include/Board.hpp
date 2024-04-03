#ifndef __BOARD_HPP
#define __BOARD_HPP

#include <iostream>
#include <vector>

#include "GameObject.hpp"
#include "Brick.hpp"

class Board : public GameObject
{
private:
    std::vector<Brick *> bricks;

public:
    Board();
    ~Board();
    void update();
    void draw();
    void collide(GameObject *other);
};

#endif // __BOARD_HPP
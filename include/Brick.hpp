#ifndef __BRICK_HPP
#define __BRICK_HPP

#include <iostream>

#include "GameObject.hpp"

enum BrickType
{
    NORMAL,
    UNBREAKABLE
};

class Brick : public GameObject
{
private:
    BrickType type;
    int health;

public:
    Brick(double x, double y, double width, double height, BrickType type, int health);
    ~Brick();
    void update();
    void draw();
    void collide(GameObject *other);
};

#endif // __BRICK_HPP
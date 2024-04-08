#ifndef __BRICK_HPP
#define __BRICK_HPP

#include <iostream>

#include "GameObject.hpp"
#include "Enums.hpp"

class Graphics;

class Brick : public GameObject
{
private:
    BrickType type;
    int health;

public:
    double width;
    double height;
    Brick(double x, double y, double width, double height, BrickType type, int health);
    ~Brick();
    void update(eMapType pMapType);
    void draw();
    void collide(GameObject *other);
};

#include "Graphics.hpp"

#endif // __BRICK_HPP
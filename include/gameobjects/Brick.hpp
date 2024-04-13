#ifndef __BRICK_HPP
#define __BRICK_HPP

#include <iostream>

#include "gameobjects/GameObject.hpp"
#include "resources/Enums.hpp"

class GraphicsManager;

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

#include "graphics/GraphicsManager.hpp"

#endif // __BRICK_HPP
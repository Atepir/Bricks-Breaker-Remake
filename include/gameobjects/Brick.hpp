#ifndef __BRICK_HPP
#define __BRICK_HPP

#include <iostream>

#include "gameobjects/GameObject.hpp"
#include "resources/Enums.hpp"

#define BRICK_WIDTH 140
#define BRICK_HEIGHT 48

class GraphicsManager;

class Brick : public GameObject
{
private:
    BrickType type;
    int health;

public:
    Brick(Point position, double width, double height, BrickType type, int health);
    ~Brick();

    void update() override;
    void draw() override;
    void collide(GameObject *other) override;
};

#include "graphics/GraphicsManager.hpp"

#endif // __BRICK_HPP
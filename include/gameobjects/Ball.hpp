#ifndef __BALL_HPP
#define __BALL_HPP

#include <iostream>
#include <cmath>

#include "gameobjects/GameObject.hpp"
#include "resources/Constants.hpp"

template <eMapType mapType>
class GraphicsManager;

class Ball : public GameObject
{
private:
    BallType type;
    double radius;
    double mass;

public:
    Ball(BallType type, Point point, double radius, double mass);
    ~Ball();

    void update() override;
    void draw() override;
    void collide(GameObject *other) override;
};

#include "graphics/GraphicsManager.hpp"

#endif // __BALL_HPP
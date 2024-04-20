#ifndef __BALL_HPP
#define __BALL_HPP

#include <iostream>
#include <cmath>

#include "gameobjects/GameObject.hpp"
#include "resources/Constants.hpp"

class ResourceManager;

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
    void collide(GameObject *other) override;
};

#include "resources/ResourceManager.hpp"

#endif // __BALL_HPP
#ifndef __BALL_HPP
#define __BALL_HPP

#include <iostream>
#include <cmath>

#include "gameobjects/GameObject.hpp"

class Ball : public GameObject
{
private:
    double radius;
    double mass;
    double x, y;

public:
    Ball(double x, double y, double radius, double mass);
    ~Ball();
    void update();
    void draw();
    void collide(GameObject *other);
};

#endif // __BALL_HPP
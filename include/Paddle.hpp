#ifndef __PADDLE_HPP
#define __PADDLE_HPP

#include <iostream>
#include <cmath>

#include "GameObject.hpp"
#include "Graphics.hpp"

class Paddle : public GameObject
{
private:
    double width;
    double height;
    double speed;

public:
    Paddle(double x, double y, double width, double height, double speed);
    ~Paddle();
    void update();
    void draw();
    void collide(GameObject *other);
};

#endif // __PADDLE_HPP
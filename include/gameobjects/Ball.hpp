#ifndef __BALL_HPP
#define __BALL_HPP

#include <iostream>
#include <cmath>

#include "gameobjects/GameObject.hpp"

class GraphicsManager;

class Ball : public GameObject
{
private:
    BallType type;
    double radius;
    double mass;
    double x, y;
    SDL_Texture *pTexture;

public:
    Ball(BallType type, double x, double y, double radius, double mass);
    ~Ball();
    void update();
    void draw();
    void collide(GameObject *other);
};

#include "graphics/GraphicsManager.hpp"

#endif // __BALL_HPP
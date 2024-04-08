#ifndef __PADDLE_HPP
#define __PADDLE_HPP

#include <iostream>
#include <cmath>

#include "GameObject.hpp"
#include "Graphics.hpp"
#include "Enums.hpp"

#define ROTATION_SPEED_MULTIPLIER 200

class Paddle : public GameObject
{
private:
    double width;
    double height;
    double speed;

    static Paddle *instance;
    SDL_Texture *pTexture;

public:
    Paddle(double x, double y, double width, double height, double speed, double angularVelocity);
    ~Paddle();
    void update(eMapType pMapType);
    void draw();
    void collide(GameObject *other);

    Paddle(const Paddle &) = delete;
    Paddle &operator=(const Paddle &) = delete;

    static Paddle *getInstance();
    double getWidth();
    double getHeight();
    double getSpeed();

    void setWidth(double width);
    void setHeight(double height);
    void setSpeed(double speed);

    SDL_Texture *getTexture();
    void setTexture(SDL_Texture *pTexture);
};

#endif // __PADDLE_HPP

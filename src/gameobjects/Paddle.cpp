#include "gameobjects/Paddle.hpp"

Point gravityCenterPoint = Point(512, 360 - 20);

void Paddle<eMapType::Basic>::update()
{
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_LEFT])
    {
        position.x -= velocity.x;
    }
    if (state[SDL_SCANCODE_RIGHT])
    {
        position.x += velocity.x;
    }
}

void Paddle<eMapType::Circular>::update()
{
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    double angle = 0;

    if (state[SDL_SCANCODE_LEFT])
    {
        angle = angularVelocity * M_PI / 180;
    }
    if (state[SDL_SCANCODE_RIGHT])
    {
        angle = -angularVelocity * M_PI / 180;
    }

    double xM = position.x - gravityCenterPoint.x;
    double yM = position.y - gravityCenterPoint.y;
    position.x = round(xM * cos(angle) - yM * sin(angle) + gravityCenterPoint.x);
    position.y = round(xM * sin(angle) + yM * cos(angle) + gravityCenterPoint.y);

    // update the angle of the paddle
    double newAngle = atan2(position.y - gravityCenterPoint.y, position.x - gravityCenterPoint.x);
    this->angle = newAngle * 180 / M_PI;
    this->angle += 90;
}
#include "gameobjects/Paddle.hpp"

using namespace GameObjects;

void Paddle<eMapType::Map_Basic>::update()
{
    // keep the paddle within the screen
    if (position.x < 0 + BORDER_WIDTH)
    {
        position.x = BORDER_WIDTH;
    }
    if (position.x + width > Graphics::Renderer::getInstance()->getScreenWidth() - BORDER_WIDTH)
    {
        position.x = Graphics::Renderer::getInstance()->getScreenWidth() - width - BORDER_WIDTH;
    }
}

void Paddle<eMapType::Map_Circular>::update()
{
}

void Paddle<eMapType::Map_Basic>::keyDownLeft()
{
    handleMouseMove(false);
}

void Paddle<eMapType::Map_Basic>::keyDownRight()
{
    handleMouseMove(true);
}

void Paddle<eMapType::Map_Circular>::keyDownLeft()
{
    handleMouseMove(false);
}

void Paddle<eMapType::Map_Circular>::keyDownRight()
{
    handleMouseMove(true);
}

template <>
void Paddle<eMapType::Map_Basic>::handleMouseMove(bool right)
{
    if (right)
    {
        position.x += velocity.x;
    }
    else
    {
        position.x -= velocity.x;
    }
}

template <>
void Paddle<eMapType::Map_Circular>::handleMouseMove(bool right)
{
    double angle = 0;
    Point gravityCenterPoint = Point(Graphics::Renderer::getInstance()->getScreenWidth() / 2 - 36, Graphics::Renderer::getInstance()->getScreenHeight() / 2 - 10);

    if (right)
    {
        angle = -angularVelocity * M_PI / 180;
    }
    else
    {
        angle = angularVelocity * M_PI / 180;
    }

    double xM = position.x - gravityCenterPoint.x;
    double yM = position.y - gravityCenterPoint.y;
    position.x = round(xM * cos(angle) - yM * sin(angle) + gravityCenterPoint.x);
    position.y = round(xM * sin(angle) + yM * cos(angle) + gravityCenterPoint.y);

    // update the angle of the paddle
    double newAngle = atan2(position.y - gravityCenterPoint.y, position.x - gravityCenterPoint.x);
    this->angle = newAngle * 180 / M_PI;
    this->angle -= 90;
}
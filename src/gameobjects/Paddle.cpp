#include "gameobjects/Paddle.hpp"

using namespace GameObjects;

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

    // keep the paddle within the screen
    if (position.x < 0 + BORDER_WIDTH)
    {
        position.x = BORDER_WIDTH;
    }
    if (position.x + width > Graphics::Renderer::getInstance()->getScreenWidth() - BORDER_WIDTH)
    {
        position.x = Graphics::Renderer::getInstance()->getScreenWidth() - width - BORDER_WIDTH;
    }

    // std::cout << "Paddle position: " << position.x << ", " << position.y << std::endl;
}

void Paddle<eMapType::Circular>::update()
{
    Point gravityCenterPoint = Point(Graphics::Renderer::getInstance()->getScreenWidth() / 2 - 36, Graphics::Renderer::getInstance()->getScreenHeight() / 2 - 10);
    std::cout << "CIRCULAR Paddle update" << std::endl;

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

    // if mouse moving to the left
    if (state[SDL_BUTTON(SDL_BUTTON_LEFT)])
    {
        angle = angularVelocity * M_PI / 180;
    }
    // if mouse moving to the right
    if (state[SDL_BUTTON(SDL_BUTTON_RIGHT)])
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
    this->angle -= 90;
}

void Paddle<eMapType::Basic>::handleMouseMove(bool right)
{
    if (right)
    {
        position.x += velocity.x;
    }
    else
    {
        position.x -= velocity.x;
    }

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

void Paddle<eMapType::Circular>::handleMouseMove(bool right)
{
    double angle = 0;
    Point gravityCenterPoint = Point(Graphics::Renderer::getInstance()->getScreenWidth() / 2 - 36, Graphics::Renderer::getInstance()->getScreenHeight() / 2 - 10);

    if (right)
    {
        angle = -angularVelocity * M_PI / 140;
    }
    else
    {
        angle = angularVelocity * M_PI / 140;
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
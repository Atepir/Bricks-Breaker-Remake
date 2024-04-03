#include "Paddle.hpp"

Paddle::Paddle(double x, double y, double width, double height, double speed)
{
}

Paddle::~Paddle()
{
}

void Paddle::update()
{
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_LEFT])
    {
        position.x -= speed;
    }
    if (state[SDL_SCANCODE_RIGHT])
    {
        position.x += speed;
    }
}

void Paddle::draw()
{
    SDL_Rect dstRect = {(int)position.x, (int)position.y, (int)width, (int)height};
    SDL_RenderCopyEx(Graphics::getInstance()->getRenderer(), pTexture, NULL, &dstRect, 0, NULL, SDL_FLIP_NONE);
}

void Paddle::collide(GameObject *other)
{
}
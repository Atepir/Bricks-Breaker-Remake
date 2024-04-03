#include "Brick.hpp"

Brick::Brick(double x, double y, double width, double height, BrickType type, int health)
{
}

Brick::~Brick()
{
}

void Brick::update()
{
}

void Brick::draw()
{
    // SDL_Rect dstRect = {(int)position.x, (int)position.y, (int)wcwidth, (int)height};
    // SDL_RenderCopyEx(renderer, pTexture, NULL, &dstRect, 0, NULL, SDL_FLIP_NONE);
}

void Brick::collide(GameObject *other)
{
}

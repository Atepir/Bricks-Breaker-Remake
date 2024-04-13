#include "gameobjects/Brick.hpp"

Brick::Brick(double x, double y, double width, double height, BrickType type, int health)
{
    this->position.x = x;
    this->position.y = y;
    this->width = width;
    this->height = height;
    this->type = type;
    this->health = health;
}

Brick::~Brick()
{
}

void Brick::update(eMapType pMapType)
{
    if (health <= 0)
    {
        delete this;
    }
}

void Brick::draw()
{
    SDL_Rect destRect = {position.x, position.y, width, height};
    SDL_SetRenderDrawColor(Graphics::getInstance()->getRenderer(), 0, 255, 0, 255);
    SDL_RenderFillRect(Graphics::getInstance()->getRenderer(), &destRect);
}

void Brick::collide(GameObject *other)
{
}

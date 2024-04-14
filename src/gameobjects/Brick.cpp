#include "gameobjects/Brick.hpp"

Brick::Brick(double x, double y, double width, double height, BrickType type, int health)
{
    this->position.x = x;
    this->position.y = y;
    this->width = width;
    this->height = height;
    this->type = type;
    this->health = health;
    this->pTexture = ResourceManager::getInstance()->getTexture("brick", type);
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
    SDL_RenderCopy(GraphicsManager::getInstance()->getRenderer(), pTexture, NULL, &destRect);
}

void Brick::collide(GameObject *other)
{
}

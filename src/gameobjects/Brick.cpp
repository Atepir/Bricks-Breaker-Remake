#include "gameobjects/Brick.hpp"

Brick::Brick(Point position, double width, double height, BrickType type, int health) : GameObject(position, {0, 0}, 0, 0, nullptr)
{
    this->width = width;
    this->height = height;
    this->type = type;
    this->health = health;

    switch (type)
    {
    case BrickType::NORMAL:
        pTexture = ResourceManager::getInstance()->getTexture("brick_normal");
        break;
    case BrickType::UNBREAKABLE:
        pTexture = ResourceManager::getInstance()->getTexture("brick_unbreakable");
        break;
    }
}

Brick::~Brick()
{
}

void Brick::update()
{
    if (health <= 0)
    {
        delete this;
    }
}

void Brick::draw()
{
    SDL_Rect destRect = {position.x, position.y, width, height};
    SDL_RenderCopy(GraphicsManager<MAP_TYPE>::getInstance()->getRenderer(), pTexture, NULL, &destRect);
}

void Brick::collide(GameObject *other)
{
}

#include "gameobjects/Brick.hpp"

Brick::Brick(Point position, double width, double height, BrickType type, int health) : GameObject(position, width, height, {0, 0}, 0, 0, nullptr)
{
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

    this->entityType = GameObjectType::GameObjectBrick;
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

void Brick::collide(GameObject *other)
{
}

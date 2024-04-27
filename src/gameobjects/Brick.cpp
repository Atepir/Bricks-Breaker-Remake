#include "gameobjects/Brick.hpp"

using namespace GameObjects;

Brick::Brick(Point position, double width, double height, BrickType type, int health) : GameObject(position, width, height, {0, 0}, 0, 0)
{
    this->mType = type;
    this->mHealth = health;

    switch (mType)
    {
    case BrickType::NORMAL:
        texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Brick_Normal);
        break;
    case BrickType::UNBREAKABLE:
        texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Brick_Unbreakable);
        break;
    }

    this->entityType = GameObjectType::GameObjectBrick;
}

Brick::~Brick()
{
}

void Brick::update()
{
    if (mHealth <= 0)
    {
        delete this;
    }
}

void Brick::collide(std::shared_ptr<GameObject> pOther)
{
}

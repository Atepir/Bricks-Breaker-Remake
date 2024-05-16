#include "gameobjects/Brick.hpp"

using namespace GameObjects;

Brick::Brick(Point position, double width, double height, eBrickType type, int health, int angle) : GameObject(position, width, height, {0, 0}, angle, 0)
{
    this->mType = type;
    this->mHealth = health;

    switch (mType)
    {
    case eBrickType::Brick_Blue:
        texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Brick_Normal);
        break;
    case eBrickType::Brick_Green:
        texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Brick_Green);
        break;
    case eBrickType::Brick_Violet:
        texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Brick_Violet);
        break;
    case eBrickType::Brick_Yellow:
        texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Brick_Yellow);
        break;
    case eBrickType::Brick_Red:
        texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Brick_Red);
        break;
    }

    this->entityType = eGameObjectType::GameObject_Brick;
}

void Brick::update()
{
    if (mHealth <= 50)
    {
        switch (mType)
        {
        case eBrickType::Brick_Blue:
            texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Brick_Normal_Damaged);
            break;
        case eBrickType::Brick_Green:
            texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Brick_Green_Damaged);
            break;
        case eBrickType::Brick_Violet:
            texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Brick_Violet_Damaged);
            break;
        case eBrickType::Brick_Yellow:
            texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Brick_Yellow_Damaged);
            break;
        case eBrickType::Brick_Red:
            texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Brick_Red_Damaged);
            break;
        }
    }
}

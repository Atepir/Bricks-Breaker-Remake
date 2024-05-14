#include "gameobjects/Brick.hpp"

using namespace GameObjects;

Brick::Brick(Point position, double width, double height, BrickType type, int health, int angle) : GameObject(position, width, height, {0, 0}, angle, 0)
{
    this->mType = type;
    this->mHealth = health;

    switch (mType)
    {
    case BrickType::BRICK_BLUE:
        texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Brick_Normal);
        break;
    case BrickType::BRICK_GREEN:
        texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Brick_Green);
        break;
    case BrickType::BRICK_VIOLET:
        texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Brick_Violet);
        break;
    case BrickType::BRICK_YELLOW:
        texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Brick_Yellow);
        break;
    case BrickType::BRICK_RED:
        texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Brick_Red);
        break;
    }

    this->entityType = GameObjectType::GameObjectBrick;
}

void Brick::update()
{
    if (mHealth <= 50)
    {
        switch (mType)
        {
        case BrickType::BRICK_BLUE:
            texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Brick_Normal_Damaged);
            break;
        case BrickType::BRICK_GREEN:
            texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Brick_Green_Damaged);
            break;
        case BrickType::BRICK_VIOLET:
            texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Brick_Violet_Damaged);
            break;
        case BrickType::BRICK_YELLOW:
            texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Brick_Yellow_Damaged);
            break;
        case BrickType::BRICK_RED:
            texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Brick_Red_Damaged);
            break;
        }
    }
}

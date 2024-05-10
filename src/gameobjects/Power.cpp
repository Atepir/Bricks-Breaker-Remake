#include "gameobjects/Power.hpp"

using namespace GameObjects;

Power::Power(PowerType type, Point point) : GameObject(point, 26, 26, Vector(0, 10), 0, 0)
{
    this->mPowerType = type;
    this->entityType = GameObjectType::GameObjectPower;

    switch (type)
    {
        case PowerType::POWERUP_EXTRA_LIFE:
            texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Powerup_Extra_Life);
            break;
        case PowerType::POWERUP_EXPAND_BALL:
            texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Powerup_Expand_Ball);
            break;
        case PowerType::POWERUP_EXPAND_PADDLE:
            texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Powerup_Expand_Paddle);
            break;
        case PowerType::POWERUP_MULTI_BALL:
            texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Powerup_Multi_Ball);
            break;
        case PowerType::POWERDOWN_SHRINK_BALL:
            texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Powerdown_Shrink_Ball);
            break;
        case PowerType::POWERDOWN_SHRINK_PADDLE:
            texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Powerdown_Shrink_Paddle);
            break;
    }
}

void Power::update() {
    position.y += velocity.y;

    if (position.y > 720 - BORDER_WIDTH) {
        mDeleteFlag = true;
    }
}

void Power::collide(std::shared_ptr<GameObject> pOther) {

    double thisLeft = position.x;
    double thisRight = position.x + getWidth();
    double thisTop = position.y;
    double thisBottom = position.y + getHeight();

    double otherLeft = pOther->getPosition().x;
    double otherRight = pOther->getPosition().x + pOther->getWidth();
    double otherTop = pOther->getPosition().y;
    double otherBottom = pOther->getPosition().y + pOther->getHeight();

    // Check for overlap between the bounding boxes of the two objects
    if (thisRight >= otherLeft && thisLeft <= otherRight &&
        thisBottom >= otherTop && thisTop <= otherBottom)
    {
        if (pOther->getEntityType() == GameObjectType::GameObjectPaddle)
        {
            notifyObserversPaddleCollided();
            mDeleteFlag = true;
        }
    }  
}

void Power::addObserver(std::shared_ptr<IPowerObserver> pPowerObserver) {
    mPowerObservers.push_back(pPowerObserver);
}

void Power::notifyObserversPaddleCollided() {
    for (auto observer : mPowerObservers) {
        observer->onPaddleCollide(mPowerType);
    }
}
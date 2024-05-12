#include "gameobjects/Power.hpp"

using namespace GameObjects;

Power::Power(PowerType type, Point point) : GameObject(point, 26, 26, Vector(10, 10), 0, 10)
{
    this->mPowerType = type;
    this->entityType = GameObjectType::GameObjectPower;

    if (MAP_TYPE == eMapType::Circular)
    {
        this->velocity.x = rand() % 10 - 5;
        this->velocity.y = rand() % 10 - 5;
    }
    else
    {
        this->velocity.y = 5;
    }

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

void Power::update()
{
    std::shared_ptr<Graphics::Renderer> renderer = Graphics::Renderer::getInstance();
    switch (MAP_TYPE)
    {
    case eMapType::Basic:
    {
        position.y += velocity.y;
        double distanceFromCenter = sqrt(pow(position.x - renderer->getScreenWidth() / 2, 2) + pow(position.y - renderer->getScreenHeight() / 2, 2));
        if (distanceFromCenter > 400 - BORDER_WIDTH)
        {
            mDeleteFlag = true;
        }
    }
        break;
    case eMapType::Circular:
        double centerX = 1024 / 2;
        double centerY = 720 / 2;
        double distanceX = position.x - centerX;
        double distanceY = position.y - centerY;
        double distance = sqrt(distanceX * distanceX + distanceY * distanceY);
        double normalizedDistanceX = distanceX / distance;
        double normalizedDistanceY = distanceY / distance;
        double repulsion = 0.1;
        velocity.x += repulsion * normalizedDistanceX;
        velocity.y += repulsion * normalizedDistanceY;
        position.x += velocity.x;
        position.y += velocity.y;
        if (position.x > renderer->getScreenWidth())
        {
            mDeleteFlag = true;
        }
        break;
    }
}

void Power::collide(std::shared_ptr<GameObject> pOther)
{

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

void Power::addObserver(std::shared_ptr<IPowerObserver> pPowerObserver)
{
    mPowerObservers.push_back(pPowerObserver);
}

void Power::notifyObserversPaddleCollided()
{
    for (auto observer : mPowerObservers)
    {
        observer->onPaddleCollide(mPowerType);
    }
}
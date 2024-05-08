#include "gameobjects/Power.hpp"

using namespace GameObjects;

Power::Power(PowerType type, Point point) : GameObject(point, 70, 70, Vector(0, 10), 0, 0)
{
    this->mPowerType = type;
    this->entityType = GameObjectType::GameObjectPower;
}

void Power::description() {
	std::cout << "The ball grew!" << std::endl;
}

void Power::update() {
    position.y += velocity.y;

    if (position.y > 720 - BORDER_WIDTH) {
        delete this;
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
            description();
            notifyObserversPaddleCollided();
            delete this;
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
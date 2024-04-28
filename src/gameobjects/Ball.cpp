#include "gameobjects/Ball.hpp"

using namespace GameObjects;

Ball::Ball(BallType type, Point point, double radius, double mass) : GameObject(point, 30, 30, Vector(0, 10), 0, 0)
{
    this->mType = type;
    this->mRadius = radius;
    this->mMass = mass;
    this->texture = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Ball_Basic);
    this->entityType = GameObjectType::GameObjectBall;
}

Ball::~Ball()
{
}

void Ball::update()
{
    position.x += velocity.x;
    position.y += velocity.y;

    if (position.x < BORDER_WIDTH || position.x > 1024 - BORDER_WIDTH)
    {
        velocity.x = -velocity.x;
    }

    if (position.y < BORDER_WIDTH + MARGIN_TOP || position.y > 720 - BORDER_WIDTH)
    {
        velocity.y = -velocity.y;
    }

    if (position.y > 720 - BORDER_WIDTH)
    {
        // has fallen off the screen
        position.y = 720;
        // notify the observers that the ball has fallen
        notifyObserversBallFallen();
        // reset the ball position
        position.x = 512;
        position.y = 400;
        velocity.x = 0;
        velocity.y = 10;
    }
}

void Ball::addObserver(std::shared_ptr<IBallObserver> observer)
{
    mObservers.push_back(observer);
}

void Ball::notifyObserversBallFallen()
{
    for (auto observer : mObservers)
    {
        observer->onBallFallen();
    }
}

void Ball::notifyObserversBrickDestroyed(BrickType pBrickType)
{
    for (auto observer : mObservers)
    {
        observer->onBrickDestroyed(pBrickType);
    }
}

void Ball::damageBrick(std::shared_ptr<Brick> pBrick, int pDamage)
{
    pBrick->mHealth -= pDamage;
    if (pBrick->mHealth <= 0)
    {
        pBrick->mDeleteFlag = true;
        notifyObserversBrickDestroyed(pBrick->mType);
    }
}

void Ball::collide(std::shared_ptr<GameObject> pOther)
{
    // Calculate the minimum and maximum coordinates of both objects
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
            double paddleCenter = pOther->getPosition().x + pOther->getWidth() / 2;
            double ballCenter = position.x + getWidth() / 2;
            double distanceFromCenter = ballCenter - paddleCenter;
            double normalizedDistance = distanceFromCenter / (pOther->getWidth() / 2);
            double bounceAngle = normalizedDistance * 45;
            velocity.x = 20 * sin(bounceAngle * M_PI / 180);
            velocity.y = -20 * cos(bounceAngle * M_PI / 180);
        }
        else if (pOther->getEntityType() == GameObjectType::GameObjectBrick)
        {
            std::shared_ptr<Brick> brick = std::static_pointer_cast<Brick>(pOther);
            switch (brick->mType)
            {
            case BrickType::BRICK_BLUE:
                damageBrick(brick, 100);
                break;
            case BrickType::BRICK_GREEN:
                damageBrick(brick, 60);
                break;
            case BrickType::BRICK_VIOLET:
                damageBrick(brick, 40);
                break;
            case BrickType::BRICK_YELLOW:
                damageBrick(brick, 20);
                break;
            case BrickType::BRICK_RED:
                damageBrick(brick, 10);
                break;
            }

            velocity.y = -velocity.y;
        }
    }
}
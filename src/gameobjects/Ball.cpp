#include "gameobjects/Ball.hpp"

using namespace GameObjects;

Ball::Ball(BallType type, Point point, double radius, double mass) : GameObject(point, 30, 30, Vector(20, 20), 0, 0)
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

    if (position.x < 0 || position.x > 1024)
    {
        velocity.x = -velocity.x;
    }

    if (position.y < 0 || position.y > 720)
    {
        velocity.y = -velocity.y;
    }

    if (position.y > 720)
    {
        position.y = 720;
    }

    if (position.y < 0)
    {
        position.y = 0;
    }

    if (position.x > 1024)
    {
        position.x = 1024;
    }

    if (position.x < 0)
    {
        position.x = 0;
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
            // bounce the ball off the paddle
            // when more at the center of the paddle, bounce straight up
            // when more at the edges of the paddle, bounce at an angle
            double paddleCenter = pOther->getPosition().x + pOther->getWidth() / 2;
            double ballCenter = position.x + getWidth() / 2;
            double distance = ballCenter - paddleCenter;
            double normalizedDistance = distance / (pOther->getWidth() / 2);
            double angle = normalizedDistance * 45;
            velocity.x = 20 * cos(angle * M_PI / 180);
            velocity.y = -20 * sin(angle * M_PI / 180);
        }
        else if (pOther->getEntityType() == GameObjectType::GameObjectBrick)
        {
            // bounce the ball off the brick
            velocity.y = -velocity.y;
            // std::cout << "Ball collided with brick" << std::endl;
        }
    }
}

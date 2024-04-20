#include "gameobjects/Ball.hpp"

Ball::Ball(BallType type, Point point, double radius, double mass) : GameObject(point, 30, 30, Vector(20, 20), 0, 0, nullptr)
{
    this->type = type;
    this->radius = radius;
    this->mass = mass;
    pTexture = ResourceManager::getInstance()->getTexture("ball_normal");

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

void Ball::collide(GameObject *other)
{
    if (other->getEntityType() == GameObjectType::GameObjectPaddle)
    {
        // if the collision happen on the left part of the paddle, then the ball will go to the left
        if (position.x + radius > other->getPosition().x && position.x < other->getPosition().x + other->getWidth())
        {
            if (position.y + radius > other->getPosition().y && position.y < other->getPosition().y + other->getHeight())
            {
                velocity.y = -velocity.y;
                velocity.x = -2;
            }
        }

        // if the collision happen on the right part of the paddle, then the ball will go to the right

        if (position.x + radius > other->getPosition().x && position.x < other->getPosition().x + other->getWidth())
        {
            if (position.y + radius > other->getPosition().y && position.y < other->getPosition().y + other->getHeight())
            {
                velocity.x = 2;
            }
        }
    }
    else if (other->getEntityType() == GameObjectType::GameObjectBrick)
    {
        if (position.y + radius > other->getPosition().y && position.y < other->getPosition().y + other->getHeight())
        {
            if (position.x + radius > other->getPosition().x && position.x < other->getPosition().x + other->getWidth())
            {
                velocity.y = -velocity.y;
            }
        }
    }
}

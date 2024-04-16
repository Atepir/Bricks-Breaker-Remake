#include "gameobjects/Ball.hpp"

Ball::Ball(BallType type, double x, double y, double radius, double mass)
{
    this->entityType = GameObjectType::GameObjectBall;
    this->type = type;
    this->position.x = x;
    this->position.y = y;
    this->radius = radius;
    this->mass = mass;
    this->pTexture = ResourceManager::getInstance()->getTexture("ball", type);

    this->velocity.x = 0;
    this->velocity.y = -3;
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

void Ball::draw()
{
    SDL_Rect destRect = {position.x, position.y, radius, radius};
    SDL_RenderCopy(GraphicsManager::getInstance()->getRenderer(), pTexture, NULL, &destRect);
}

void Ball::collide(GameObject *other)
{
    if (other->entityType == GameObjectType::GameObjectPaddle)
    {
        // if the collision happen on the left part of the paddle, then the ball will go to the left
        if (position.x + radius > other->position.x && position.x < other->position.x + 160)
        {
            if (position.y + radius > other->position.y && position.y < other->position.y + 20)
            {
                velocity.y = -velocity.y;
                velocity.x = -2;
            }
        }

        // if the collision happen on the right part of the paddle, then the ball will go to the right

        if (position.x + radius > other->position.x && position.x < other->position.x + 160)
        {
            if (position.y + radius > other->position.y && position.y < other->position.y + 20)
            {
                velocity.y = -velocity.y;
                velocity.x = 2;
            }
        }
    }
    else if (other->entityType == GameObjectType::GameObjectBrick)
    {
        if (position.y + radius > other->position.y && position.y < other->position.y + 30)
        {
            if (position.x + radius > other->position.x && position.x < other->position.x + 30)
            {
                velocity.y = -velocity.y;
            }
        }
    }
}

#include "gameobjects/Ball.hpp"

Ball::Ball(BallType type, double x, double y, double radius, double mass)
{
    this->type = type;
    this->position.x = x;
    this->position.y = y;
    this->radius = radius;
    this->mass = mass;
    this->pTexture = ResourceManager::getInstance()->getTexture("ball", type);
}

Ball::~Ball()
{
}

void Ball::update()
{
}

void Ball::draw()
{
    SDL_Rect destRect = {position.x, position.y, radius, radius};
    SDL_RenderCopy(GraphicsManager::getInstance()->getRenderer(), pTexture, NULL, &destRect);
}

void Ball::collide(GameObject *other)
{
}

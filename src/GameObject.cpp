#include "GameObject.hpp"

GameObject::GameObject(Point position, Vector velocity, double angle, double angularVelocity, double scale, SDL_Texture *pTexture)
{
    this->position = position;
    this->velocity = velocity;
    this->angle = angle;
    this->angularVelocity = angularVelocity;
    this->scale = scale;
    this->pTexture = pTexture;
}

GameObject::GameObject()
{
    this->position = Point(0, 0);
    this->velocity = Vector(0, 0);
    this->angle = 0;
    this->angularVelocity = 0;
    this->scale = 1;
    this->pTexture = nullptr;
}

GameObject::~GameObject()
{
}

void GameObject::update()
{
}

void GameObject::draw()
{
}
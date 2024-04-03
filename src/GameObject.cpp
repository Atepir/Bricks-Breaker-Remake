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
#include "gameobjects/GameObject.hpp"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

GameObject::GameObject(Point position, Vector velocity, double angle, double angularVelocity, SDL_Texture *pTexture)
{
    this->position = position;
    this->velocity = velocity;
    this->angle = angle;
    this->angularVelocity = angularVelocity;
    this->pTexture = pTexture;
}

void GameObject::update()
{
}

void GameObject::draw()
{
}

void GameObject::collide(GameObject *other)
{
}
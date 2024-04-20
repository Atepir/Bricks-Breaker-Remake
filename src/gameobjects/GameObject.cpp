#include "gameobjects/GameObject.hpp"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

GameObject::GameObject(Point position, double width, double height, Vector velocity, double angle, double angularVelocity, SDL_Texture *pTexture)
{
    this->width = width;
    this->height = height;
    this->position = position;
    this->velocity = velocity;
    this->angle = angle;
    this->angularVelocity = angularVelocity;
    this->pTexture = pTexture;
}

void GameObject::update()
{
}

void GameObject::collide(GameObject *other)
{
}
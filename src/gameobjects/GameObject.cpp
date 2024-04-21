#include "gameobjects/GameObject.hpp"

using namespace GameObjects;

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

GameObject::GameObject(Point position, double width, double height, Vector velocity, double angle, double angularVelocity)
{
    this->width = width;
    this->height = height;
    this->position = position;
    this->velocity = velocity;
    this->angle = angle;
    this->angularVelocity = angularVelocity;
}

void GameObject::update()
{
}

void GameObject::collide(GameObject *other)
{
}
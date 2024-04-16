#ifndef __GAMEOBJECT_HPP
#define __GAMEOBJECT_HPP

#include <SDL.h>
#include <iostream>

#include "geometry/Point.hpp"
#include "geometry/Vector.hpp"
#include "resources/Enums.hpp"

class GameObject
{
protected:
    Vector velocity;
    double angle;
    double angularVelocity;
    double scale;
    SDL_Texture *pTexture = nullptr;

public:
    GameObjectType entityType;
    Point position;
    GameObject();
    GameObject(Point position, Vector velocity, double angle, double angularVelocity, double scale, SDL_Texture *pTexture);
    ~GameObject();
    void update();
    void draw();
};

#endif // __GAMEOBJECT_HPP
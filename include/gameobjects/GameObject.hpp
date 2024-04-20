#ifndef __GAMEOBJECT_HPP
#define __GAMEOBJECT_HPP

#include <SDL.h>
#include <iostream>

#include "geometry/Point.hpp"
#include "geometry/Vector.hpp"
#include "resources/Enums.hpp"
#include "graphics/Drawable.hpp"

/**
 * @brief Abstract class that represents a game object
 */
class GameObject : public Drawable
{
protected:
    GameObjectType entityType;
    Point position;
    Vector velocity;

    double angle;
    double angularVelocity;

    double width;
    double height;

public:
    GameObject();

    /**
     * @brief Constructs a new GameObject object
     *
     * @param position The position of the object
     * @param velocity The velocity of the object
     * @param angle The angle of the object
     * @param angularVelocity The angular velocity of the object
     * @param pTexture The texture of the object
     */
    GameObject(Point position, double width, double height, Vector velocity, double angle, double angularVelocity, SDL_Texture *pTexture);

    ~GameObject();

    double getWidth() { return width; }
    double getHeight() { return height; }

    Point getPosition() { return position; }

    GameObjectType getEntityType() { return entityType; }

    void render(GraphicsManager &renderer) override
    {
        // std::cout << "Rendering GameObject: " << entityType << " at position: " << position.x << ", " << position.y << " with texture: " << pTexture << std::endl;
        renderer.draw(pTexture, position, width, height, angle);
    }

#pragma region Virtual methods
    virtual void update();
    virtual void collide(GameObject *other) = 0;
#pragma endregion
};

#endif // __GAMEOBJECT_HPP
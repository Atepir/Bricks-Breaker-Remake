#ifndef __GAMEOBJECT_HPP
#define __GAMEOBJECT_HPP

#include <iostream>

#include "geometry/Point.hpp"
#include "geometry/Vector.hpp"
#include "resources/Enums.hpp"
#include "graphics/Drawable.hpp"

using namespace Geometry;
using namespace Graphics;

namespace GameObjects
{
    /**
     * @brief Abstract class that represents a game object.
     * @details This class is the base class for all game objects in the game. It provides the basic properties and methods that all game objects should have.
     */
    class GameObject : public IDrawable
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
        GameObject() = default;

        /**
         * @brief Constructs a new GameObject object
         *
         * @param position The position of the object
         * @param velocity The velocity of the object
         * @param angle The angle of the object
         * @param angularVelocity The angular velocity of the object
         */
        GameObject(Point position, double width, double height, Vector velocity, double angle, double angularVelocity)
            : position(position), width(width), height(height), velocity(velocity), angle(angle), angularVelocity(angularVelocity) {}

        ~GameObject() {}

        double getWidth() { return width; }
        double getHeight() { return height; }
        double getAngle() { return angle; }

        Point getPosition() { return position; }

        GameObjectType getEntityType() { return entityType; }

        void render(Graphics::Renderer &pRenderer) override
        {
            pRenderer.draw(texture->getTexture(), position, width, height, angle);
        }

#pragma region Virtual methods
        /**
         * @brief Method that updates the object
         * @details Derived classes should implement this method to update the object's state such as position, velocity, etc.
         */
        virtual void update() {};

        /**
         * @brief Method that handles the collision of the object with another object
         * @details Derived classes should implement this method to handle the collision of the object with another object
         *
         * @param pOther The other object that this object collided with
         */
        virtual void collide(std::shared_ptr<GameObject> pOther) {};
#pragma endregion
    };
}

#endif // __GAMEOBJECT_HPP
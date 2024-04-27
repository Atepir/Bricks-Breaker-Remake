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
     * @brief Abstract class that represents a game object
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
        GameObject();

        /**
         * @brief Constructs a new GameObject object
         *
         * @param position The position of the object
         * @param velocity The velocity of the object
         * @param angle The angle of the object
         * @param angularVelocity The angular velocity of the object
         */
        GameObject(Point position, double width, double height, Vector velocity, double angle, double angularVelocity);

        ~GameObject();

        double getWidth() { return width; }
        double getHeight() { return height; }

        Point getPosition() { return position; }

        GameObjectType getEntityType() { return entityType; }

        void render(Graphics::Renderer &pRenderer) override
        {
            // std::cout << "Rendering GameObject: "
            //           << " at position: " << position.x << ", " << position.y << " with texture: " << texture << std::endl;
            // std::cout << "Width: " << width << " Height: " << height << " Angle: " << angle << std::endl;
            pRenderer.draw(texture->getTexture(), position, width, height, angle);
        }

#pragma region Virtual methods
        /**
         * @brief Method that updates the object
         * @details Derived classes should implement this method to update the object's state such as position, velocity, etc.
         */
        virtual void update();

        /**
         * @brief Method that handles the collision of the object with another object
         * @details Derived classes should implement this method to handle the collision of the object with another object
         *
         * @param pOther The other object that this object collided with
         */
        virtual void collide(std::shared_ptr<GameObject> pOther) = 0;
#pragma endregion
    };
}

#endif // __GAMEOBJECT_HPP
#ifndef __IMAGE_HPP
#define __IMAGE_HPP

#include "graphics/Texture.hpp"
#include "gui/UiElement.hpp"

using namespace Graphics;

namespace Gui
{
    /**
     * @brief Represents an image on the screen
     * @details An image is a UI element that displays a texture on the screen
     */
    class Image : public UiElement
    {
    public:
        Image(std::shared_ptr<Texture> texture, Point position, int width, int height) : UiElement(position.x, position.y, width, height)
        {
            this->texture = texture;
        }

        inline void setTexture(std::shared_ptr<Texture> pTexture) { this->texture = texture; }

        virtual void render(Renderer &renderer) override
        {
            renderer.draw(texture->getTexture(), Point(x, y), width, height, 0);
        }
    };
}

#endif
#ifndef __IMAGE_HPP
#define __IMAGE_HPP

#include "graphics/Texture.hpp"
#include "gui/UiElement.hpp"

using namespace Graphics;

namespace Gui
{
    class Image : public UiElement
    {
    public:
        Image(std::shared_ptr<Texture> texture, Point position, int width, int height);

        void setTexture(std::shared_ptr<Texture> pTexture);

        virtual void render(Renderer &renderer);

        void update() override
        {
        }
    };
}

#endif
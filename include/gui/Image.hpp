#ifndef __IMAGE_HPP
#define __IMAGE_HPP

#include "graphics/Texture.hpp"
#include "gui/UiElement.hpp"

using namespace Graphics;

class Image : public UiElement
{
private:
    Texture *texture;

public:
    Image(Texture *texture);
    Image(Texture *texture, int width, int height);

    virtual void render(GraphicsManager &renderer);
};

#endif
#include "gui/Image.hpp"

using namespace Gui;

Image::Image()
{
}

void Image::setTexture(Texture *pTexture)
{
    this->texture = texture;
}

void Image::render(Graphics::GraphicsManager &renderer)
{
    renderer.draw(texture->getTexture(), Point(x, y), width, height, 0);
}
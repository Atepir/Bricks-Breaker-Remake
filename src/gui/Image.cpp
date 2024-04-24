#include "gui/Image.hpp"

using namespace Gui;

Image::Image(Texture *texture, Point position, int width, int height) : UiElement(position.x, position.y, width, height)
{
    this->texture = texture;
}

void Image::setTexture(Texture *pTexture)
{
    this->texture = texture;
}

void Image::render(Graphics::GraphicsManager &renderer)
{
    renderer.draw(texture->getTexture(), Point(x, y), width, height, 0);
}
#include "gui/Image.hpp"

using namespace Gui;

Image::Image(std::shared_ptr<Texture> texture, Point position, int width, int height) : UiElement(position.x, position.y, width, height)
{
    this->texture = texture;
}

void Image::setTexture(std::shared_ptr<Texture> pTexture)
{
    this->texture = texture;
}

void Image::render(Graphics::Renderer &renderer)
{
    renderer.draw(texture->getTexture(), Point(x, y), width, height, 0);
}
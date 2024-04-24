#include "gui/Button.hpp"

using namespace Graphics;

Button::Button(int id, std::string text, Point position, int width, int height) : id(id), UiElement(position.x, position.y, width, height)
{
    this->text = text;
    this->font = new Font(text, eColor::ColorCyan);
}

void Button::render(Graphics::GraphicsManager &renderer)
{
    renderer.drawRect(x, y, width, height);

    renderer.drawText(font, x + getWidth() / 2 - font->getWidth() / 2,
                      y + getHeight() / 2 - font->getHeight() / 2);
}

Button *Button::setClickListener(ClickListener *listener)
{
    this->listener = listener;
    return this;
}

void Button::handleMouseUp(SDL_MouseButtonEvent *event)
{
    std::cout << "hmu btn" << std::endl;
    if (listener == nullptr)
        return;
    if (event->button == SDL_BUTTON_LEFT)
    {
        std::cout << "left click" << std::endl;
        listener->onClick(id);
    }
}

Button::~Button()
{
    // delete listener.get();
}
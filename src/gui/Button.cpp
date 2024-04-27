#include "gui/Button.hpp"

using namespace Graphics;
using namespace Gui;

Button::Button(std::string text, Point position, int width, int height, eColor fgColor) : UiElement(position.x, position.y, width, height)
{
    this->text = text;
    this->font = Font(text, fgColor);
}

void Button::render(Graphics::Renderer &renderer)
{
    renderer.drawRect(x - BUTTON_TEXT_PADDING, y - BUTTON_TEXT_PADDING, width + BUTTON_TEXT_PADDING + 6, height + BUTTON_TEXT_PADDING + 12);

    renderer.drawText(font, x,
                      y, width, height);
}

void Button::handleMouseUp(Type_SDL_MouseButtonEvent event)
{
    std::cout << "hmu btn" << std::endl;
    if (event->button == SDL_BUTTON_LEFT)
    {
        std::cout << "left click" << std::endl;
        if (
            event->x < x - BUTTON_TEXT_PADDING || event->x > x + width + BUTTON_TEXT_PADDING || event->y < y - BUTTON_TEXT_PADDING || event->y > y + height + BUTTON_TEXT_PADDING)
        {
            return;
        }
        if (onClickCallback)
        {
            onClickCallback();
        }
    }
}

Button::~Button()
{
}
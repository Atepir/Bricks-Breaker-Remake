#include "gui/Button.hpp"

using namespace Graphics;

Button::Button(std::string text, Point position, int width, int height, eColor fgColor) : UiElement(position.x, position.y, width, height)
{
    this->text = text;
    this->font = new Font(text, fgColor);
}

void Button::render(Graphics::GraphicsManager &renderer)
{
    renderer.drawRect(x - 12, y - 12, width + 18, height + 24);

    renderer.drawText(font, x,
                      y, width, height);
}

void Button::handleMouseUp(SDL_MouseButtonEvent *event)
{
    std::cout << "hmu btn" << std::endl;
    if (event->button == SDL_BUTTON_LEFT)
    {
        std::cout << "left click" << std::endl;
        if (event->x < x - 12 || event->x > x + width + 12 || event->y < y - 12 || event->y > y + height + 12)
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
    // delete listener.get();
}
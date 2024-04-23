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

std::shared_ptr<Button> Button::setClickListener(std::shared_ptr<ClickListener> listener)
{
    this->listener = listener;
    return std::shared_ptr<Button>(this);
}

void Button::buttonReleased(std::shared_ptr<SDL_MouseButtonEvent> event)
{
    if (listener == nullptr)
        return;
    if (event->button == SDL_BUTTON_LEFT)
        listener->onClick(id);
}

Button::~Button()
{
    // delete listener.get();
}
#include "gui/Label.hpp"

using namespace Gui;
using namespace Graphics;

Label::Label(std::string text, Point position, int width, int height) : UiElement(position.x, position.y, width, height)
{
    std::cout << "Creating label" << std::endl;
    font = new Font(text, eColor::ColorWhite);
}

Label *Label::setText(std::string text)
{
    this->text = text;
    font->setText(text, eColor::ColorWhite);
    return this;
}

void Label::render(Graphics::GraphicsManager &renderer)
{
    std::cout << "Rendering label" << std::endl;
    renderer.drawText(font, x, y, width, height);
}
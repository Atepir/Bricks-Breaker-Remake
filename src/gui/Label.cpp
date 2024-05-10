#include "gui/Label.hpp"

using namespace Gui;
using namespace Graphics;

Label::Label(std::string text, Point position, int width, int height, eColor color)
    : UiElement(position.x, position.y, width, height)
{
    // std::cout << "Creating label" << std::endl;
    font = Font(text, color);
}

void Label::setText(std::string pText, eColor color)
{
    text = pText;
    font.setText(pText, color);
}

void Label::render(Graphics::Renderer &renderer)
{
    // std::cout << "Rendering label" << std::endl;
    renderer.drawText(font, x, y, width, height);
}
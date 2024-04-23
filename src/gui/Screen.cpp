#include "gui/Screen.hpp"

using namespace Gui;

Screen::Screen()
{
}

Screen::~Screen()
{
    for (auto &element : children)
    {
        delete element;
    }
}

void Screen::init()
{
}

void Screen::render(Graphics::GraphicsManager &renderer)
{
    std::cout << "children size: " << children.size() << std::endl;
    std::cout << "Rendering screen" << std::endl;
    for (auto &element : children)
    {
        element->render(renderer);
    }
}

void Screen::update(double delta)
{
    for (auto &element : children)
    {
        element->update(delta);
    }
}

void Screen::resize(int width, int height)
{
    for (auto &element : children)
    {
        element->resize(width, height);
    }
}

UiElement *Screen::add(UiElement *element)
{
    children.push_back(element);
    return element;
}
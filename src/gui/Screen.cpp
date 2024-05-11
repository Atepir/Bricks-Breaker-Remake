#include "gui/Screen.hpp"

using namespace Gui;

Screen::Screen()
{
}

Screen::~Screen()
{
    for (auto &element : children)
    {
        element.reset();
    }
}

void Screen::init()
{
}

void Screen::render(Graphics::Renderer &renderer)
{
    // std::cout << "children size: " << children.size() << std::endl;
    // std::cout << "Rendering screen" << std::endl;
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

void Screen::handleMouseDown(Type_SDL_MouseButtonEvent event)
{
    for (auto &element : children)
    {
        element->handleMouseDown(event);
    }
}

void Screen::handleMouseUp(Type_SDL_MouseButtonEvent event)
{
    for (auto &element : children)
    {
        element->handleMouseUp(event);
    }
}

void Screen::handleMouseMoveX(bool right)
{
    for (auto &element : mMouseMoveListeners)
        element->handleMouseMove(right);
}

void Screen::resize(int width, int height)
{
    for (auto &element : children)
    {
        element->resize(width, height);
    }
}

std::shared_ptr<UiElement> Screen::add(std::shared_ptr<UiElement> element)
{
    children.push_back(element);
    return element;
}

void Screen::addMouseMoveListener(std::shared_ptr<IMouseMoveListener> listener)
{
    mMouseMoveListeners.push_back(listener);
}

void Screen::remove(std::shared_ptr<UiElement> element)
{
    children.erase(std::remove(children.begin(), children.end(), element), children.end());
}
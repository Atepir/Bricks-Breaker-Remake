#include "gui/Screen.hpp"

using namespace Gui;

Screen::~Screen()
{
    for (auto &element : mChildren)
    {
        element.reset();
    }
}

void Screen::render(Graphics::Renderer &renderer)
{
    for (auto &element : mChildren)
    {
        element->render(renderer);
    }
}

void Screen::handleMouseDown(std::shared_ptr<SDL_MouseButtonEvent> pEvent)
{
    for (auto &element : mChildren)
    {
        element->handleMouseDown(pEvent);
    }
}

void Screen::handleKeyDown(bool pRight)
{
    if (pRight)
        for (auto &element : mMoveListeners)
            element->keyDownRight();
    else
        for (auto &element : mMoveListeners)
            element->keyDownLeft();
}

void Screen::handleMouseUp(Type_SDL_MouseButtonEvent pEvent)
{
    for (auto &element : mChildren)
    {
        element->handleMouseUp(pEvent);
    }
}

void Screen::handleMouseMoveX(bool pRight)
{
    for (auto &element : mMoveListeners)
        element->handleMouseMove(pRight);
}

std::shared_ptr<UiElement> Screen::add(std::shared_ptr<UiElement> pElement)
{
    mChildren.push_back(pElement);
    return pElement;
}

void Screen::addMoveListener(std::shared_ptr<IMoveListener> pListener)
{
    mMoveListeners.push_back(pListener);
}

void Screen::remove(std::shared_ptr<UiElement> pElement)
{
    mChildren.erase(std::remove(mChildren.begin(), mChildren.end(), pElement), mChildren.end());
}
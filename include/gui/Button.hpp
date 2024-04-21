#ifndef __BUTTON_HPP
#define __BUTTON_HPP

#include "gui/UiElement.hpp"
#include <iostream>

class ClickListener
{
public:
    virtual void onClick(int buttonId) = 0;
};

class Button : public UiElement
{
private:
    int id;
    std::string text;
    int textWidth, textHeight;
    ClickListener *listener;

public:
    Button(int id, std::string text, int width, int height);
    virtual ~Button();

    Button *setListener(ClickListener *listener);

    virtual void buttonReleased(SDL_MouseButtonEvent *event);

    virtual void render(Graphics::GraphicsManager &renderer);
};

#endif
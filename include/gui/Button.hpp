#ifndef __BUTTON_HPP
#define __BUTTON_HPP

#include "gui/UiElement.hpp"
#include "graphics/Font.hpp"
#include "graphics/GraphicsManager.hpp"
#include <iostream>

using namespace Graphics;

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
    Font *font;

public:
    Button(int id, std::string text, Point position, int width, int height);
    virtual ~Button();

    Button *setClickListener(ClickListener *listener);

    void handleMouseUp(SDL_MouseButtonEvent *event) override;

    virtual void render(Graphics::GraphicsManager &renderer);

    void update() override {}
};

#endif
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
    void onClick(int buttonId) {}
};

class Button : public UiElement
{
private:
    int id;
    std::string text;
    int textWidth, textHeight;
    std::shared_ptr<ClickListener> listener;
    Font *font;

public:
    Button(int id, std::string text, Point position, int width, int height);
    virtual ~Button();

    std::shared_ptr<Button> setClickListener(std::shared_ptr<ClickListener> listener);

    virtual void buttonReleased(std::shared_ptr<SDL_MouseButtonEvent> event);

    virtual void render(Graphics::GraphicsManager &renderer);

    void update() override {}
};

#endif
#ifndef __BUTTON_HPP
#define __BUTTON_HPP

#include "gui/UiElement.hpp"
#include "graphics/Font.hpp"
#include "graphics/GraphicsManager.hpp"
#include <iostream>
#include <functional>

using namespace Graphics;

class Button : public UiElement
{
private:
    std::string text;
    int textWidth, textHeight;
    Font *font;
    std::function<void()> onClickCallback;

public:
    Button(std::string text, Point position, int width, int height, eColor fgColor);
    virtual ~Button();

    void handleMouseUp(SDL_MouseButtonEvent *event) override;

    void setOnClickCallback(std::function<void()> callback) { onClickCallback = callback; }

    virtual void render(Graphics::GraphicsManager &renderer);

    void update() override {}
};

#endif
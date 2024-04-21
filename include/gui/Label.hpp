#ifndef __LABEL_HPP
#define __LABEL_HPP

#include "gui/UiElement.hpp"
#include "graphics/GraphicsManager.hpp"

class Label : public UiElement
{
private:
    int id;
    std::string text;

public:
    Label(std::string text);
    Label(std::string text, bool big);

    virtual void render(Graphics::GraphicsManager &renderer);
};

#endif
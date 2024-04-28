#ifndef __LABEL_HPP
#define __LABEL_HPP

#include "gui/UiElement.hpp"
#include "graphics/Renderer.hpp"
#include "graphics/Font.hpp"
#include "resources/Enums.hpp"

namespace Gui
{
    class Label : public UiElement
    {
    private:
        int id;
        std::string text;
        Graphics::Font font;

    public:
        Label(std::string text, Point position, int width, int height, eColor color = eColor::ColorWhite);

        void setText(std::string pText, eColor color = eColor::ColorWhite);

        virtual void render(Graphics::Renderer &renderer);
        void update() override{};
    };
}

#endif
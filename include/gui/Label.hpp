#ifndef __LABEL_HPP
#define __LABEL_HPP

#include "gui/UiElement.hpp"
#include "graphics/Renderer.hpp"
#include "graphics/Font.hpp"
#include "resources/Enums.hpp"

namespace Gui
{
    /**
     * @brief Label class
     * @details A label is a UI element that displays text
     */
    class Label : public UiElement
    {
    private:
        int id;
        std::string text;
        Graphics::Font font;

    public:
        Label(std::string text, Point position, int width, int height, eColor color = eColor::ColorWhite) : UiElement(position.x, position.y, width, height)
        {
            font = Graphics::Font(text, color);
        }

        inline void setText(std::string pText, eColor color = eColor::ColorWhite)
        {
            text = pText;
            font.setText(pText, color);
        }

        virtual void render(Graphics::Renderer &renderer) override
        {
            renderer.drawText(font, x, y, width, height);
        }
    };
}

#endif
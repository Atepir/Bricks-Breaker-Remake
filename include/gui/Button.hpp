#ifndef __BUTTON_HPP
#define __BUTTON_HPP

#include "gui/UiElement.hpp"
#include "graphics/Font.hpp"
#include "graphics/Renderer.hpp"
#include <iostream>
#include <functional>

#define BUTTON_TEXT_PADDING 12

using namespace Graphics;

namespace Gui
{
    /**
     * @brief Button class
     * @details A button is a clickable UI element that can be rendered on the screen
     */
    class Button : public UiElement
    {
    private:
        std::string text;
        int textWidth, textHeight;
        Font font;
        /**
         * @brief Callback lambda function that is called when the button is clicked
         */
        std::function<void()> onClickCallback;

    public:
        Button(std::string text, Point position, int width, int height, eColor fgColor) : UiElement(position.x, position.y, width, height)
        {
            this->text = text;
            this->font = Font(text, fgColor);
        }

        virtual ~Button() = default;

        inline void handleMouseUp(Point pClickPoint) override
        {
            if (
                pClickPoint.x >= x - BUTTON_TEXT_PADDING &&
                pClickPoint.x <= x + width + BUTTON_TEXT_PADDING &&
                pClickPoint.y >= y - BUTTON_TEXT_PADDING &&
                pClickPoint.y <= y + height + BUTTON_TEXT_PADDING)

                if (onClickCallback)
                {
                    onClickCallback();
                }
        }

        inline void setOnClickCallback(std::function<void()> callback) { onClickCallback = callback; }

        virtual void render(Renderer &renderer) override
        {
            renderer.drawRect(x - BUTTON_TEXT_PADDING, y - BUTTON_TEXT_PADDING, width + BUTTON_TEXT_PADDING + 6, height + BUTTON_TEXT_PADDING + 12);

            renderer.drawText(font, x,
                              y, width, height);
        }
    };
}

#endif
#ifndef __UI_ELEMENT_HPP
#define __UI_ELEMENT_HPP

#include "graphics/Drawable.hpp"
#include "gui/EventListener.hpp"

namespace Gui
{
    using Type_SDL_MouseButtonEvent = SDL_MouseButtonEvent *;

    /**
     * @brief Base class for all UI elements
     * @details A UI element is a drawable object that can handle events
     */
    class UiElement : public Graphics::IDrawable, public Gui::IClickListener
    {
    protected:
        int x, y, width, height;

    public:
        UiElement() = default;
        UiElement(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}
        ~UiElement() = default;
    };
}
#endif
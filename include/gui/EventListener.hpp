#ifndef __EVENTLISTENER_H
#define __EVENTLISTENER_H

#include <SDL.h>

namespace Gui
{
    using Type_SDL_KeyboardEvent = SDL_KeyboardEvent *;
    using Type_SDL_MouseButtonEvent = SDL_MouseButtonEvent *;

    /**
     * @brief Interface for handling mouse click events
     */
    class IClickListener
    {
    public:
        virtual void handleMouseDown(std::shared_ptr<SDL_MouseButtonEvent> event) {}
        virtual void handleMouseUp(Type_SDL_MouseButtonEvent event) {}
    };

    /**
     * @brief Interface for handling keyboard and mouse move events
     */
    class IMoveListener
    {
    public:
        virtual void handleMouseMove(bool right) = 0;
        virtual void keyDownLeft() = 0;
        virtual void keyDownRight() = 0;
    };
}

#endif
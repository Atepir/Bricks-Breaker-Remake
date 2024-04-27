#ifndef __EVENTLISTENER_H
#define __EVENTLISTENER_H

#include <SDL.h>

namespace Gui
{
    using Type_SDL_KeyboardEvent = SDL_KeyboardEvent *;
    using Type_SDL_MouseButtonEvent = SDL_MouseButtonEvent*;

    class EventListener
    {
    public:
        void keyUp(Type_SDL_KeyboardEvent event) {}
        virtual void keyDown(Type_SDL_KeyboardEvent event) {}
        virtual void handleMouseDown(Type_SDL_MouseButtonEvent event)
        {
            std::cout << "handleMouseDown" << std::endl;
        }
        virtual void handleMouseUp(Type_SDL_MouseButtonEvent event)
        {
            std::cout << "handleMouseUp" << std::endl;
        }
    };
}

#endif
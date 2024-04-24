#ifndef __EVENTLISTENER_H
#define __EVENTLISTENER_H

#include <SDL.h>

namespace Gui
{
    class EventListener
    {
    public:
        void keyUp(SDL_KeyboardEvent *event) {}
        virtual void keyDown(SDL_KeyboardEvent *event) {}
        virtual void handleMouseDown(SDL_MouseButtonEvent *event)
        {
            std::cout << "handleMouseDown" << std::endl;
        }
        virtual void handleMouseUp(SDL_MouseButtonEvent *event)
        {
            std::cout << "handleMouseUp" << std::endl;
        }
    };
}

#endif
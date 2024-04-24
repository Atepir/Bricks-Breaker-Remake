#ifndef __EVENTMANAGER_HPP
#define __EVENTMANAGER_HPP

#include <SDL.h>

#include "core/App.hpp"

namespace Core
{
    class EventManager
    {
    private:
        static EventManager *pInstance;

    public:
        EventManager() = default;
        ~EventManager() = default;

        static EventManager *getInstance();

        void handleEvents();
    };
}

#endif // __EVENTMANAGER_HPP
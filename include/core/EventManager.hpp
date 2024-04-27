#ifndef __EVENTMANAGER_HPP
#define __EVENTMANAGER_HPP

#include <SDL.h>

#include "core/App.hpp"

namespace Core
{
    class EventManager
    {
    private:
        static std::shared_ptr<EventManager> pInstance;

    public:
        EventManager() = default;
        ~EventManager() = default;

        static std::shared_ptr<EventManager> getInstance();

        void handleEvents();
    };
}

#endif // __EVENTMANAGER_HPP
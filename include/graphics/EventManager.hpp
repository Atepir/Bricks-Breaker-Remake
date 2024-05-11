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
        int mPrevMouseX = 0;
        bool mIsMovingRight = false;

    public:
        EventManager() = default;
        ~EventManager() = default;

        static std::shared_ptr<EventManager> getInstance();

        void handleEvents();

        EventManager(const EventManager &) = delete;
        EventManager &operator=(const EventManager &) = delete;
    };
}

#endif // __EVENTMANAGER_HPP
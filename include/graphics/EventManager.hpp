#ifndef __EVENTMANAGER_HPP
#define __EVENTMANAGER_HPP

#include <SDL.h>

#include "core/App.hpp"

#define MOUSE_MOVE_THRESHOLD 1

namespace Core
{
    /**
     * @brief High level event manager singleton
     */
    class EventManager
    {
    private:
        static inline std::shared_ptr<EventManager> pInstance = nullptr;
        int mPrevMouseX = 0;
        bool mIsMovingRight = false;

    public:
        EventManager() = default;
        ~EventManager() = default;

        static std::shared_ptr<EventManager> getInstance()
        {
            if (pInstance == nullptr)
            {
                pInstance = std::make_shared<EventManager>();
            }
            return pInstance;
        }

        void handleEvents()
        {
            SDL_Event event;
            const Uint8 *state = SDL_GetKeyboardState(NULL);
            std::shared_ptr<App> app = App::getInstance();

            if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A])
            {
                if (app != nullptr)
                    if (app->getCurrentScreen() != nullptr)
                        app->getCurrentScreen()->handleKeyDown(false);
            }
            else if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D])
            {
                if (app != nullptr)
                    if (app->getCurrentScreen() != nullptr)
                        app->getCurrentScreen()->handleKeyDown(true);
            }

            while (SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                case SDL_QUIT:
                    if (app != nullptr)
                        app->quit();
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (app != nullptr)
                        if (app->getCurrentScreen() != nullptr)
                        {
                            Point mousePosition = {(double)event.button.x, (double)event.button.y};
                            app->getCurrentScreen()->handleMouseDown(mousePosition);
                        }
                case SDL_MOUSEBUTTONUP:
                    if (app != nullptr)
                        if (app->getCurrentScreen() != nullptr)
                        {
                            Point mousePosition = { (double)event.button.x, (double)event.button.y};
                            app->getCurrentScreen()->handleMouseUp(mousePosition);
                        }
                case SDL_MOUSEMOTION:
                {
                    // if mouse is not pressed, skip
                    if (event.motion.state == 0)
                        break;

                    int mouseX = event.motion.x;

                    if (mouseX > mPrevMouseX + MOUSE_MOVE_THRESHOLD)
                        mIsMovingRight = true;
                    else if (mouseX < mPrevMouseX - MOUSE_MOVE_THRESHOLD)
                        mIsMovingRight = false;

                    mPrevMouseX = mouseX;
                    if (app != nullptr)
                        if (app->getCurrentScreen() != nullptr)
                            app->getCurrentScreen()
                                ->handleMouseMoveX(mIsMovingRight);
                }
                }
            }
        }

        EventManager(const EventManager &) = delete;
        EventManager &operator=(const EventManager &) = delete;
    };
}

#endif // __EVENTMANAGER_HPP
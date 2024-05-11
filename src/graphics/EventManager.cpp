#include "graphics/EventManager.hpp"

using namespace Core;

std::shared_ptr<EventManager> EventManager::pInstance = nullptr;

std::shared_ptr<EventManager> EventManager::getInstance()
{
    if (pInstance == nullptr)
    {
        pInstance = std::make_shared<EventManager>();
    }
    return pInstance;
}

void EventManager::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        std::shared_ptr<App> app = App::getInstance();
        switch (event.type)
        {
        case SDL_QUIT:
            if (app != nullptr)
                app->quit();
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (app != nullptr)
                app->getCurrentScreen()->handleMouseDown(&event.button);
        case SDL_MOUSEBUTTONUP:
            if (app != nullptr)
                app->getCurrentScreen()->handleMouseUp(&event.button);
        case SDL_MOUSEMOTION:
        {
            int mouseX = event.motion.x;

            if (mouseX > mPrevMouseX)
                mIsMovingRight = true;
            else
                mIsMovingRight = false;

            mPrevMouseX = mouseX;
            if (app != nullptr)
            {
                if (app->getCurrentScreen() != nullptr)
                    app->getCurrentScreen()
                        ->handleMouseMoveX(mIsMovingRight);
            }
        }
        }
    }
}
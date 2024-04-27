#include "core/EventManager.hpp"

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
        switch (event.type)
        {
        case SDL_QUIT:
            App::getInstance()->quit();
            break;
        case SDL_MOUSEBUTTONDOWN:
            App::getInstance()->getCurrentScreen()->handleMouseDown(&event.button);
        case SDL_MOUSEBUTTONUP:
            App::getInstance()->getCurrentScreen()->handleMouseUp(&event.button);
        }
    }
}
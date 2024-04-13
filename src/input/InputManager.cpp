#include "input/InputManager.hpp"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

void InputManager::update()
{
    Game *pGame = Game::getInstance();
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            pGame->quit();
            break;
        case SDL_KEYDOWN:
            pGame->buttonPressed((event.key.keysym.sym));
            break;
        case SDL_KEYUP:
            break;
        case SDL_MOUSEMOTION:
            break;
        case SDL_MOUSEBUTTONDOWN:
            break;
        case SDL_MOUSEBUTTONUP:
            break;
        default:
            break;
        }
    }
}
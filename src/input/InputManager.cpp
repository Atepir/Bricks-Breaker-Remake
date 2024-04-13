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
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                pGame->quit();
                break;
            case SDLK_LEFT:
                pGame->buttonPressed(eButton::LEFT);
            case SDLK_RIGHT:
                pGame->buttonPressed(eButton::RIGHT);
            case SDLK_SPACE:
                pGame->buttonPressed(eButton::SPACE);
            default:
                break;
            }
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
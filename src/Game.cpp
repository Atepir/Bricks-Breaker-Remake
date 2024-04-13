#include "Game.hpp"

Game *Game::pInstance = nullptr;

Game::Game()
{
    mRunning = true;
    mWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    mRenderer = new Renderer(mWindow);
}

Game::~Game()
{
    delete mRenderer;
    SDL_DestroyWindow(mWindow);
}

void Game::run()
{
    while (mRunning)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                mRunning = false;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                buttonPressed(event.key.keysym.sym);
            }
        }

        mRenderer->clear();
        mRenderer->render();
    }
}

void Game::quit()
{
    mRunning = false;
}

void Game::buttonPressed(SDL_Keycode pKey)
{
    switch (pKey)
    {
    case SDLK_ESCAPE:
        quit();
        break;
    case SDLK_LEFT:
        break;
    case SDLK_RIGHT:
        break;
    case SDLK_SPACE:
        break;
    default:
        break;
    }
}


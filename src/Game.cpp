#include "Game.hpp"

Game *Game::pInstance = nullptr;

Game::Game()
{
}

Game::~Game()
{
    quit();
}

void Game::run()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Echec de l'initialisation de la SDL " << SDL_GetError() << std::endl;
    }
    eMapType mapType = eMapType::Basic;

    GraphicsManager graphics = GraphicsManager(mapType);
    graphics.init();

    Paddle *paddle = Paddle::getInstance();
    Ball *ball = new Ball(BallType::NORMAL, 512, 360, 30, 1);

    while (mRunning)
    {
        SDL_Event event;
        while (mRunning && SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit();
                break;
            default:
                break;
            }
        }

        // Keyboard input management
        int nbk;
        const Uint8 *keys = SDL_GetKeyboardState(&nbk);
        if (keys[SDL_SCANCODE_ESCAPE])
            quit();

        graphics.draw();
        graphics.update();
        ball->draw();

        // Limit frame rate to 60 fps
        SDL_Delay(16); // utiliser SDL_GetTicks64() pour plus de precisions
    }
    SDL_Quit(); // Quit SDL
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

Game *Game::getInstance()
{
    if (pInstance == nullptr)
    {
        pInstance = new Game();
    }
    return pInstance;
}

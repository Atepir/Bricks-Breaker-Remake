#include "Game.hpp"

#define mapType eMapType::Basic

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

    GraphicsManager<MAP_TYPE> *graphics = GraphicsManager<MAP_TYPE>::getInstance();
    graphics->init();

    Paddle<MAP_TYPE> *paddle = Paddle<MAP_TYPE>::getInstance();
    BallFactory ballFactory = BallFactory();

    Ball *ball = ballFactory.createBall(BallType::NORMAL);
    Board<MAP_TYPE> *board = new Board<MAP_TYPE>();

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

        graphics->update();
        graphics->draw();
        ball->update();
        ball->draw();

        ball->collide(paddle);
        std::vector<Brick *> bricks = Board<mapType>::getInstance()->getBricks();
        for (auto &brick : bricks)
        {
            ball->collide(brick);
        }

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

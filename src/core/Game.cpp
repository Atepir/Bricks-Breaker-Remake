#include "core/Game.hpp"

using namespace GameObjects;
using namespace Factories;
using namespace Graphics;
using namespace Core;

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
    Graphics::GraphicsManager *graphics = Graphics::GraphicsManager::getInstance();

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

        ball->collide(paddle);
        std::vector<Brick *> bricks = Board<MAP_TYPE>::getInstance()->getBricks();
        for (auto &brick : bricks)
        {
            ball->collide(brick);
        }

        graphics->clear();

        ball->update();
        paddle->update();
        board->update();

        for (auto &brick : bricks)
        {
            brick->render(*graphics);
        }

        ball->render(*graphics);
        paddle->render(*graphics);

        graphics->render();

        // Limit frame rate to 60 fps
        SDL_Delay(1000 / 20);
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

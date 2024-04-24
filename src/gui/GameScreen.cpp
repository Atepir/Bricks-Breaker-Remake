#include "gui/Screen.hpp"
#include "core/Game.hpp"

using namespace Gui;

GameScreen::GameScreen()
{
}

void GameScreen::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Echec de l'initialisation de la SDL " << SDL_GetError() << std::endl;
    }

    Graphics::GraphicsManager *graphics = Graphics::GraphicsManager::getInstance();
    graphics->init();

    Core::Game *game = Core::Game::getInstance();
    game->run();
}

void GameScreen::render(Graphics::GraphicsManager &renderer)
{
    Screen::render(renderer);
}

GameScreen::~GameScreen()
{
}

void GameScreen::keyUp(std::shared_ptr<SDL_KeyboardEvent> event)
{
}

void GameScreen::keyDown(std::shared_ptr<SDL_KeyboardEvent> event)
{
}

void GameScreen::update(double delta)
{
    Screen::update(delta);
}
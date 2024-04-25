#include "gui/Screen.hpp"
#include "core/Game.hpp"
#include "gui/Button.hpp"

using namespace Gui;

GameScreen::GameScreen()
{
}

void GameScreen::init()
{
    Core::Game *game = Core::Game::getInstance();
    Button *pauseButton = new Button("Pause", {50, 600}, 200, 50, eColor::ColorBlue);
    pauseButton->setOnClickCallback(
        []()
        {
            Core::App::getInstance()->setScreen(new MainMenuScreen());
        });
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
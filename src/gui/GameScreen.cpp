#include "gui/Screen.hpp"
#include "core/Game.hpp"
#include "gui/Button.hpp"

using namespace Gui;

GameScreen::GameScreen()
{
}

void GameScreen::init()
{
    std::shared_ptr<Core::Game> game = Core::Game::getInstance();
    Button pauseButton = Button("Pause", {50, 600}, 200, 50, eColor::ColorBlue);
    pauseButton.setOnClickCallback(
        []()
        {
            Core::App::getInstance()->setScreen(std::make_shared<MainMenuScreen>());
        });
    game->run();
}

void GameScreen::render(Graphics::Renderer &renderer)
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
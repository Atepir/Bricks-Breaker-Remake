
#include "gui/Screen.hpp"
#include "gui/Button.hpp"
#include "gui/Label.hpp"

using namespace Gui;

MainMenuScreen::MainMenuScreen()
{
}

void MainMenuScreen::init()
{
    add(new Label("BricksBreaker Remake!", {180, 100}, 700, 60));
    Button *startButton = new Button("Play", {420, 500}, 200, 50, eColor::ColorBlue);
    startButton->setOnClickCallback(
        []()
        {
            Core::App::getInstance()->setScreen(new GameScreen());
        });
    add(startButton);

    Button *exitButton = new Button("Exit", {420, 600}, 200, 50, eColor::ColorRed);
    exitButton->setOnClickCallback(
        []()
        {
            Core::App::getInstance()->quit();
        });
    add(exitButton);

    background = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Main_Menu_Background);

    std::cout << "Main menu screen initialized" << std::endl;
}

void MainMenuScreen::render(Graphics::GraphicsManager &renderer)
{

    Graphics::GraphicsManager *graphics = Graphics::GraphicsManager::getInstance();

    graphics->draw(background->getTexture(), {0, 0}, 1024, 800, 0);
    Screen::render(renderer);
}

MainMenuScreen::~MainMenuScreen()
{
    delete background;
}

#include "gui/Screen.hpp"
#include "gui/Button.hpp"
#include "gui/Label.hpp"

using namespace Gui;

MainMenuScreen::MainMenuScreen()
{
}

void MainMenuScreen::init()
{
    add(new Label("BricksBreaker Remake!", {300, 100}, 100, 50));
    add((new Button(0, "Play", {300, 500}, 100, 50))->setClickListener(this));

    background = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Main_Menu_Background);

    std::cout << "Main menu screen initialized" << std::endl;
}

void MainMenuScreen::render(Graphics::GraphicsManager &renderer)
{

    Graphics::GraphicsManager *graphics = Graphics::GraphicsManager::getInstance();

    graphics->draw(background->getTexture(), {0, 0}, 1024, 800, 0);
    Screen::render(renderer);
}

void MainMenuScreen::onClick(int buttonId)
{
    std::cout << "Button clicked: " << buttonId << std::endl;
    switch (buttonId)
    {
    case 0:
        Core::App::getInstance()->setScreen(new GameScreen());
        break;
    }
}

MainMenuScreen::~MainMenuScreen()
{
    delete background;
}
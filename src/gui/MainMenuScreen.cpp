
#include "gui/Screen.hpp"
#include "gui/Button.hpp"
#include "gui/Label.hpp"
#include "gui/Image.hpp"

using namespace Gui;

void MainMenuScreen::init()
{
    double screenWidth = Graphics::Renderer::getInstance()->getScreenWidth();
    double screenHeight = Graphics::Renderer::getInstance()->getScreenHeight();

    add(std::make_shared<Label>(Label("BricksBreaker Remake!", {screenWidth / 2 - 360, 100}, 700, 60)));
    Button startButton = Button("Play", {screenWidth / 2 - 120, 500}, 200, 50, eColor::Color_Blue);
    startButton.setOnClickCallback(
        []()
        {
            Resources::LevelManager::setLevel(0);
            Core::App::getInstance()->setScreen(std::make_shared<GameScreen>());
        });
    add(std::make_shared<Button>(startButton));

    Button exitButton = Button("Exit", {screenWidth / 2 - 100, 600}, 160, 50, eColor::Color_Red);
    exitButton.setOnClickCallback(
        []()
        {
            Core::App::getInstance()->quit();
        });
    add(std::make_shared<Button>(exitButton));

    mBackground = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Main_Menu_Background);

    std::cout
        << "Main menu screen initialized" << std::endl;
}

void MainMenuScreen::render(Graphics::Renderer &renderer)
{
    renderer.draw(mBackground->getTexture(), {0, 0}, renderer.getScreenWidth(), renderer.getScreenHeight(), 0);
    Screen::render(renderer);
}
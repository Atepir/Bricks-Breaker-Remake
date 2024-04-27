
#include "gui/Screen.hpp"
#include "gui/Button.hpp"
#include "gui/Label.hpp"
#include "gui/Image.hpp"

using namespace Gui;

MainMenuScreen::MainMenuScreen()
{
}

void MainMenuScreen::init()
{
    add(std::make_shared<Label>(Label("BricksBreaker Remake!", {180, 100}, 700, 60)));
    Button startButton = Button("Play", {420, 500}, 200, 50, eColor::ColorBlue);
    startButton.setOnClickCallback(
        []()
        {
            Core::App::getInstance()->setScreen(std::make_shared<GameScreen>());
        });
    add(std::make_shared<Button>(startButton));

    Button exitButton = Button("Exit", {420, 600}, 200, 50, eColor::ColorRed);
    exitButton.setOnClickCallback(
        []()
        {
            Core::App::getInstance()->quit();
        });
    add(std::make_shared<Button>(exitButton));

    Image bg = Image(Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Main_Menu_Background), {0, 0}, 1024, 800);
    add(std::make_shared<Image>(bg));

    std::cout << "Main menu screen initialized" << std::endl;
}

void MainMenuScreen::render(Graphics::Renderer &renderer)
{
    Screen::render(renderer);
}

MainMenuScreen::~MainMenuScreen()
{
    // background.reset();
}
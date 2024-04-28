
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
    // sleep one second to avoid overlapping with the previous screen
    // std::this_thread::sleep_for(std::chrono::seconds(1));
    add(std::make_shared<Label>(Label("BricksBreaker Remake!", {180, 100}, 700, 60)));
    Button startButton = Button("Play", {420, 500}, 200, 50, eColor::ColorBlue);
    startButton.setOnClickCallback(
        []()
        {
            Resources::LevelManager::setLevel(0);
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

    background = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Main_Menu_Background);

    std::cout
        << "Main menu screen initialized" << std::endl;
}

void MainMenuScreen::render(Graphics::Renderer &renderer)
{
    renderer.draw(background->getTexture(), {0, 0}, 1024, 800, 0);
    Screen::render(renderer);
}

MainMenuScreen::~MainMenuScreen()
{
    // background.reset();
}
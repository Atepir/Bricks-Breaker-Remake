
#include "gui/Screen.hpp"
#include "gui/Button.hpp"
#include "gui/Label.hpp"
#include "gui/Image.hpp"

using namespace Gui;

void GameOverScreen::init()
{
    double screenWidth = Graphics::Renderer::getInstance()->getScreenWidth();
    double screenHeight = Graphics::Renderer::getInstance()->getScreenHeight();

    add(std::make_shared<Label>(Label("Game Over!", {screenWidth / 2 - 220, 100}, 500, 60)));

    std::string scoreText = "Your score: " + std::to_string(mScore);
    add(std::make_shared<Label>(Label(scoreText, {screenWidth / 2 - 140, 300}, 300, 50)));

    Button startButton = Button("Play again", {screenWidth / 2 - 100, 500}, 250, 50, eColor::ColorBlue);
    startButton.setOnClickCallback(
        []()
        {
            Core::App::getInstance()->setScreen(std::make_shared<GameScreen>());
        });
    add(std::make_shared<Button>(startButton));

    Button exitButton = Button("Main menu", {screenWidth / 2 - 120, 600}, 300, 50, eColor::ColorRed);
    exitButton.setOnClickCallback(
        []()
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            Core::App::getInstance()->setScreen(std::make_shared<MainMenuScreen>());
        });
    add(std::make_shared<Button>(exitButton));

    mBackground = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Main_Menu_Background);
}

void GameOverScreen::render(Graphics::Renderer &renderer)
{
    renderer.draw(mBackground->getTexture(), {(double)0, (double)0}, renderer.getScreenWidth(), renderer.getScreenHeight(), 0);
    Screen::render(renderer);
}
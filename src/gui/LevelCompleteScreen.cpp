#include "gui/Screen.hpp"
#include "gui/Button.hpp"
#include "gui/Label.hpp"
#include "gui/Image.hpp"
#include "resources/LevelManager.hpp"

using namespace Gui;

void LevelCompleteScreen::init()
{
    mWinSound = std::make_unique<Sound>("sound/valorant-ace-sound.mp3");
    mWinSound->play();
    double screenWidth = Graphics::Renderer::getInstance()->getScreenWidth();
    double screenHeight = Graphics::Renderer::getInstance()->getScreenHeight();

    add(std::make_shared<Label>(Label("Level Complete!", {screenWidth / 2 - 220, 100}, 500, 60)));

    std::string scoreText = "Your score: " + std::to_string(mScore);
    add(std::make_shared<Label>(Label(scoreText, {screenWidth / 2 - 140, 300}, 300, 50)));

    bool hasNextLevel = true;
    switch (MAP_TYPE)
    {
    case eMapType::Basic:
        hasNextLevel = Resources::LevelManager::getCurrentLevel() < Resources::LevelManager::getNumberOfLevels();
        break;
    case eMapType::Circular:
        hasNextLevel = Resources::LevelManager::getCurrentCircularLevel() < Resources::LevelManager::getNumberOfCircularLevels();
        break;
    }
    if (hasNextLevel)
    {
        Button startButton = Button("Next level", {screenWidth / 2 - 100, 500}, 250, 50, eColor::ColorBlue);
        startButton.setOnClickCallback(
            []()
            {
                switch (MAP_TYPE)
                {
                case eMapType::Basic:
                    Resources::LevelManager::setLevel(Resources::LevelManager::getCurrentLevel() + 1);
                    break;
                case eMapType::Circular:
                    Resources::LevelManager::setCircularLevel(Resources::LevelManager::getCurrentCircularLevel() + 1);
                    break;
                }

                Core::App::getInstance()
                    ->setScreen(std::make_shared<GameScreen>());
            });
        add(std::make_shared<Button>(startButton));
    }

    Button exitButton = Button("Main menu", {screenWidth / 2 - 120, 600}, 300, 50, eColor::ColorRed);
    exitButton.setOnClickCallback(
        []()
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            Core::App::getInstance()->setScreen(std::make_shared<MainMenuScreen>());
        });
    add(std::make_shared<Button>(exitButton));

    mBackground = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Main_Menu_Background);

    std::cout
        << "Main menu screen initialized" << std::endl;
}

void LevelCompleteScreen::render(Graphics::Renderer &renderer)
{
    renderer.draw(mBackground->getTexture(), {(double)0, (double)0}, renderer.getScreenWidth(), renderer.getScreenHeight(), 0);
    Screen::render(renderer);
}
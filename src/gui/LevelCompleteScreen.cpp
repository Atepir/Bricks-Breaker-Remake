#include "gui/Screen.hpp"
#include "gui/Button.hpp"
#include "gui/Label.hpp"
#include "gui/Image.hpp"
#include "resources/LevelManager.hpp"

using namespace Gui;

LevelCompleteScreen::LevelCompleteScreen(int score)
{
    // std::cout << "Level complete screen created" << std::endl;
    mScore = score;
}

void LevelCompleteScreen::init()
{
    add(std::make_shared<Label>(Label("Level Complete!", {300, 100}, 500, 60)));

    std::string scoreText = "Your score: " + std::to_string(mScore);
    add(std::make_shared<Label>(Label(scoreText, {380, 300}, 300, 50)));

    Button startButton = Button("Next level", {420, 500}, 250, 50, eColor::ColorBlue);
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

    Button exitButton = Button("Main menu", {400, 600}, 300, 50, eColor::ColorRed);
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
    renderer.draw(mBackground->getTexture(), {0, 0}, 1024, 800, 0);
    Screen::render(renderer);
}

LevelCompleteScreen::~LevelCompleteScreen()
{
    // background.reset();
}
#include "gui/Screen.hpp"
#include "gui/Button.hpp"
#include "gui/Image.hpp"
#include "gui/Label.hpp"
#include "factories/PowerFactory.hpp"

using namespace Gui;
using namespace GameObjects;
using namespace Factories;
using namespace Graphics;
using namespace Core;

GameScreen::GameScreen()
{
    this->mRenderer = Graphics::Renderer::getInstance();

    this->mPaddle = Paddle<MAP_TYPE>::getInstance();

    BallFactory ballFactory = BallFactory();
    this->mBall = ballFactory.createBall(BallType::NORMAL);

    std::shared_ptr<PowerFactory> powerFactory = std::make_shared<PowerFactory>();

    this->mBoard = Board<MAP_TYPE>::getInstance();
    this->mBoard->reset();

    this->mPlayer = std::make_shared<Player>();

    this->mBall->addObserver(mPlayer);
    this->mBall->addObserver(powerFactory);

    this->mHearts = std::vector<std::shared_ptr<Image>>();

    this->mScoreLabel = std::make_shared<Label>(Label("Score: 0", {430, 0}, 200, 30, eColor::ColorBlue));
}

void GameScreen::init()
{
    Button backButton = Button("Quit", {920, 0}, 80, 30, eColor::ColorRed);
    backButton.setOnClickCallback(
        []()
        {
            Core::App::getInstance()->setScreen(std::make_shared<MainMenuScreen>());
        });
    add(std::make_shared<Button>(backButton));

    int playerLives = mPlayer->getLives();

    for (int i = 0; i < playerLives; i++)
    {
        std::shared_ptr<Texture> heart = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Heart);
        std::shared_ptr<Image> image = std::make_shared<Image>(Image(heart, {(double)10 + i * 40, (double)0}, 30, 30));
        mHearts.push_back(image);
        add(image);
    }

    add(mScoreLabel);

    Label levelLabel = Label("Level " + std::to_string(Resources::LevelManager::getCurrentLevel() + 1), {460, 40}, 120, 30, eColor::ColorBlue);
    add(std::make_shared<Label>(levelLabel));

    mBackground = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Board_Border_Background);
}

void GameScreen::render(Graphics::Renderer &renderer)
{
    mBall->collide(mPaddle);
    std::vector<std::shared_ptr<Brick>> bricks = Board<MAP_TYPE>::getInstance()->getBricks();
    for (auto brick : bricks)
    {
        mBall->collide(brick);
    }

    mRenderer->clear();

    if (mHearts.size() > mPlayer->getLives())
    {
        remove(mHearts.back());
        mHearts.pop_back();
    }

    mScoreLabel->setText("Score: " + std::to_string(mPlayer->getScore()), eColor::ColorBlue);

    if (mPlayer->getLives() == 0)
    {
        Core::App::getInstance()->setScreen(std::make_shared<GameOverScreen>(mPlayer->getScore()));
    }

    mBall->update();
    mPaddle->update();
    mBoard->update();

    mRenderer->draw(mBackground->getTexture(), {0, 80}, 1024, 650, 0);
    for (auto &brick : bricks)
    {
        brick->render(*mRenderer);
    }

    mBall->render(*mRenderer);
    mPaddle->render(*mRenderer);
    Screen::render(renderer);

    if (mBoard->isFinished())
    {
        Core::App::getInstance()->setScreen(std::make_shared<LevelCompleteScreen>(mPlayer->getScore()));
    }
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
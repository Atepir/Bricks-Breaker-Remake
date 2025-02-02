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

    this->mPlayer = std::make_shared<Player>();

    this->mBoard = Board<MAP_TYPE>::getInstance();
    this->mBoard->reset();

    this->mPaddle = Paddle<MAP_TYPE>::getInstance();
    this->mPaddle->resetPaddle();

    this->mPowerFactory =
        PowerFactory::getInstance();
    this->mPowerFactory->resetPowers();
    this->mPowerFactory->setPlayer(mPlayer);

    this->mBallFactory = BallFactory::getInstance();
    this->mBallFactory->resetBalls();

    this->mBallFactory->addObserver(mPlayer);
    this->mBallFactory->addObserver(mPowerFactory);
    this->mBallFactory->addObserver(mBallFactory);

    mBallFactory->createBall(eBallType::Ball_Normal);

    this->mHearts = std::vector<std::shared_ptr<Image>>();

    this->mScoreLabel = std::make_shared<Label>(Label("Score: 0", {(double)mRenderer->getScreenWidth() / 2 - 110, 0}, 200, 30, eColor::Color_Blue));
}

void GameScreen::init()
{
    addMoveListener(mPaddle);

    Button backButton = Button("Quit", {(double)mRenderer->getScreenWidth() - 100, 0}, 80, 30, eColor::Color_Red);
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

    Label levelLabel = Label("Level " + std::to_string(MAP_TYPE == eMapType::Map_Basic ? Resources::LevelManager::getCurrentLevel() + 1 : Resources::LevelManager::getCurrentCircularLevel() + 1), {(double)mRenderer->getScreenWidth() / 2 - 80, 40}, 120, 30, eColor::Color_Blue);
    add(std::make_shared<Label>(levelLabel));

    switch (MAP_TYPE)
    {
    case eMapType::Map_Basic:
        mBackground = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Board_Border_Background);
        break;
    case eMapType::Map_Circular:
        // mBackground = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Circular_Board_Background);
        mBackground = nullptr;
        break;
    }
}

void GameScreen::render(Graphics::Renderer &renderer)
{
    mBallFactory->collide(mPaddle);
    mPowerFactory->collide(mPaddle);
    std::vector<std::shared_ptr<Brick>> bricks = Board<MAP_TYPE>::getInstance()->getBricks();
    for (auto brick : bricks)
    {
        mBallFactory->collide(brick);
    }

    mRenderer->clear();

    if (mHearts.size() > mPlayer->getLives())
    {
        remove(mHearts.back());
        mHearts.pop_back();
    }
    else
    {
        for (int i = mHearts.size(); i < mPlayer->getLives(); i++)
        {
            std::shared_ptr<Texture> heart = Resources::ResourceManager::getInstance()->getTexture(eTextureKey::Texture_Heart);
            std::shared_ptr<Image> image = std::make_shared<Image>(Image(heart, {(double)10 + i * 40, (double)0}, 30, 30));
            mHearts.push_back(image);
            add(image);
        }
    }

    mScoreLabel->setText("Score: " + std::to_string(mPlayer->getScore()), eColor::Color_Blue);

    if (mPlayer->getLives() == 0)
    {
        Core::App::getInstance()->setScreen(std::make_shared<GameOverScreen>(mPlayer->getScore()));
    }

    switch (MAP_TYPE)
    {
    case eMapType::Map_Basic:
        mRenderer->draw(mBackground->getTexture(), {(double)0, (double)80}, renderer.getScreenWidth(), renderer.getScreenHeight(), 0);
        break;
    case eMapType::Map_Circular:
        // mRenderer->draw(mBackground->getTexture(), {(double)0 + renderer.getDeltaWidth() / 2, (double)0 + renderer.getDeltaHeight() / 2}, 1024, 720, 0);
        break;
    }

    mBallFactory->update();
    mPaddle->update();
    mBoard->update();
    mPowerFactory->update();

    for (auto &brick : bricks)
    {
        brick->render(*mRenderer);
    }

    mBallFactory->render(*mRenderer);
    mPaddle->render(*mRenderer);
    mPowerFactory->render(*mRenderer);
    Screen::render(renderer);

    if (mBoard->isFinished())
    {
        Core::App::getInstance()->setScreen(std::make_shared<LevelCompleteScreen>(mPlayer->getScore()));
    }
}
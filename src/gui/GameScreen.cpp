#include "gui/Screen.hpp"
#include "gui/Button.hpp"
#include "gui/Image.hpp"
#include "gui/Label.hpp"

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

    this->mBoard = Board<MAP_TYPE>::getInstance();

    this->mPlayer = std::make_shared<Player>();

    this->mBall->addObserver(mPlayer);

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

    for (auto &brick : bricks)
    {
        brick->render(*mRenderer);
    }

    mBall->render(*mRenderer);
    mPaddle->render(*mRenderer);

    Screen::render(renderer);
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
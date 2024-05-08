#include "factories/BallFactory.hpp"

using namespace Factories;
using namespace GameObjects;

void BallFactory::createBall(BallType pType)
{
    std::shared_ptr<Ball> ball = nullptr;
    int padding = 120;
    int ballX = rand() % WINDOW_WIDTH;
    ballX = ballX < padding ? padding : ballX;
    ballX = ballX > WINDOW_WIDTH - padding ? WINDOW_WIDTH - padding : ballX;

    switch (pType)
    {
    case BallType::NORMAL:
        ball = std::make_shared<Ball>(BallType::NORMAL, Point(ballX, WINDOW_HEIGHT / 2), 30, 20);
        break;
    default:
        break;
    }

    mBalls.push_back(ball);
}

void BallFactory::update()
{
    for (auto &ball : mBalls)
    {
        ball->update();
    }
}

void BallFactory::render(Graphics::Renderer &pRenderer)
{
    for (auto &ball : mBalls)
    {
        ball->render(pRenderer);
    }
}

void BallFactory::destroyBall(std::shared_ptr<Ball> pBall)
{
    mBalls.erase(std::remove(mBalls.begin(), mBalls.end(), pBall), mBalls.end());
}

void BallFactory::onBallFallen(std::shared_ptr<Ball> pBall)
{
    if (mBalls.size() == 1)
    {
        mBalls.begin()->reset();
    }
    else {
        destroyBall(pBall);
    }
}

void BallFactory::collide(std::shared_ptr<GameObjects::GameObject> pGameObject)
{
    for (auto &ball : mBalls)
    {
        ball->collide(pGameObject);
    }
}

void BallFactory::addObserver(std::shared_ptr<GameObjects::IBallObserver> pObserver)
{
    for (auto &ball : mBalls)
    {
        ball->addObserver(pObserver);
    }
}

void BallFactory::onPaddleCollide(PowerType pPowerType) {
    switch (pPowerType)
    {
    case PowerType::POWERUP_EXPAND_BALL:
        for (auto &ball : mBalls)
        {
            ball->expand();
        }
        break;
    case PowerType::POWERDOWN_SHRINK_BALL:
        for (auto &ball : mBalls)
        {
            ball->shrink();
        }
        break;
    case PowerType::POWERUP_MULTI_BALL:
        for (int i = 0; i < 2; i++){
            createBall(BallType::NORMAL);
        }
        break;
    default:
        break;
    }
}
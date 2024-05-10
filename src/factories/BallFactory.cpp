#include "factories/BallFactory.hpp"

using namespace Factories;
using namespace GameObjects;

void BallFactory::createBall(BallType pType)
{
    std::shared_ptr<Ball<MAP_TYPE>> ball = nullptr;
    int padding = 120;
    int ballX = rand() % WINDOW_WIDTH;
    ballX = ballX < padding ? padding : ballX;
    ballX = ballX > WINDOW_WIDTH - padding ? WINDOW_WIDTH - padding : ballX;

    switch (pType)
    {
    case BallType::NORMAL:
        ball = std::make_shared<Ball<MAP_TYPE>>(BallType::NORMAL, Point(ballX, WINDOW_HEIGHT / 2), 30, 20);
        ball->setId(mLastGeneratedBallId++);
        break;
    default:
        break;
    }

    for (auto observer : mBallObservers)
    {
        ball->addObserver(observer);
    }
    mBalls.push_back(ball);
}

void BallFactory::update()
{
    for (auto &ball : mBalls)
    {
        if (ball == nullptr)
        {
            continue;
        }

        ball->update();
    }
}

void BallFactory::render(Graphics::Renderer &pRenderer)
{
    for (auto &ball : mBalls)
    {
        if (ball == nullptr)
        {
            continue;
        }

        ball->render(pRenderer);
    }
}

void BallFactory::destroyBall(int pBallId)
{
    for (auto it = mBalls.begin(); it != mBalls.end(); ++it)
    {
        if ((*it)->getId() == pBallId)
        {
            mBalls.erase(it);
            break;
        }
    }
}

void BallFactory::onBallFallen(int pBallId)
{
    // std::cout << "Ball fallen, remaining balls: " << mBalls.size() << std::endl;

    if (mBalls.size() == 1)
    {
        mBalls.clear();
        createBall(BallType::NORMAL);
    }
    else
    {
        destroyBall(pBallId);
    }
    // std::cout << "After update: " << mBalls.size() << std::endl;
}

void BallFactory::collide(std::shared_ptr<GameObjects::GameObject> pGameObject)
{
    for (auto &ball : mBalls)
    {
        if (ball == nullptr)
        {
            continue;
        }

        ball->collide(pGameObject);
    }
}

void BallFactory::addObserver(std::shared_ptr<GameObjects::IBallObserver> pObserver)
{
    mBallObservers.push_back(pObserver);
}

void BallFactory::onPaddleCollide(PowerType pPowerType)
{
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
        for (int i = 0; i < 2; i++)
        {
            createBall(BallType::NORMAL);
        }
        break;
    default:
        break;
    }
}

#include "factories/BallFactory.hpp"

using namespace Factories;
using namespace GameObjects;

void BallFactory::createBall(eBallType pType)
{
    std::shared_ptr<Ball<MAP_TYPE>> ball = nullptr;
    int windowWidth = Graphics::Renderer::getInstance()->getScreenWidth();
    int windowHeight = Graphics::Renderer::getInstance()->getScreenHeight();

    int padding = 120;
    int ballX = rand() % windowHeight;
    ballX = ballX < padding ? padding : ballX;
    ballX = ballX > windowWidth - padding ? windowWidth - padding : ballX;

    int ballY = windowHeight / 2 + 50;

    if (MAP_TYPE == eMapType::Map_Circular)
    {
        ballX = windowWidth / 2;
        ballY = windowHeight / 2 + 20;
    }

    switch (pType)
    {
    case eBallType::Ball_Normal:
        ball = std::make_shared<Ball<MAP_TYPE>>(eBallType::Ball_Normal, Point(ballX, ballY), 30);
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
    if (mBalls.size() == 1)
    {
        mBalls.clear();
        createBall(eBallType::Ball_Normal);
    }
    else
    {
        destroyBall(pBallId);
    }
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

void BallFactory::onPaddleCollide(ePowerType pPowerType)
{
    switch (pPowerType)
    {
    case ePowerType::PowerUp_Expand_Ball:
        for (auto &ball : mBalls)
        {
            ball->expand();
        }
        break;
    case ePowerType::PowerDown_Shrink_Ball:
        for (auto &ball : mBalls)
        {
            ball->shrink();
        }
        break;
    case ePowerType::PowerUp_Multi_Ball:
        for (int i = 0; i < 2; i++)
        {
            createBall(eBallType::Ball_Normal);
        }
        break;
    default:
        break;
    }
}

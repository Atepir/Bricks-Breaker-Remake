#include "factories/BallFactory.hpp"

using namespace Factories;
using namespace GameObjects;

std::shared_ptr<GameObjects::Ball> BallFactory::createBall(BallType pType)
{
    switch (pType)
    {
    case BallType::NORMAL:
        return std::make_shared<Ball>(BallType::NORMAL, Point(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), 30, 20);
    case BallType::EXPLOSIVE:
        return std::make_shared<Ball>(BallType::EXPLOSIVE, Point(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), 50, 50);
    default:
        return nullptr;
    }
}
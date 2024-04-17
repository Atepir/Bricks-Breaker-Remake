#include "factories/BallFactory.hpp"

Ball *BallFactory::createBall(BallType pType)
{
    switch (pType)
    {
    case BallType::NORMAL:
        return new Ball(BallType::NORMAL, Point(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), 30, 20);
    case BallType::EXPLOSIVE:
        return new Ball(BallType::EXPLOSIVE, Point(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), 50, 50);
    default:
        return nullptr;
    }
}
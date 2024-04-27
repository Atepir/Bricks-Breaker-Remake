#include "gameobjects/Board.hpp"

using namespace GameObjects;

Board<eMapType::Basic>::Board<eMapType::Basic>()
{
    mBricks = std::vector<std::shared_ptr<Brick>>();
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            mBricks.push_back(std::make_shared<Brick>(Point(BOARD_PADDING + i * (BRICK_WIDTH + 1), BOARD_PADDING + j * (BRICK_HEIGHT + 1)), BRICK_WIDTH, BRICK_HEIGHT, BrickType::NORMAL, 1));
        }
    }
}

Board<eMapType::Circular>::Board<eMapType::Circular>()
{
    mBricks = std::vector<std::shared_ptr<Brick>>();
    for (int i = 0; i < 360; i += 30)
    {
        // must be different layers from
        // the center of the circle
        mBricks.push_back(std::make_shared<Brick>(Point(512 + 100 * cos(i * M_PI / 180), 360 + 100 * sin(i * M_PI / 180)), 50, 20, BrickType::NORMAL, 1));
    }
}

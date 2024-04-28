#include "gameobjects/Board.hpp"

using namespace GameObjects;

void Board<eMapType::Basic>::fillBasicBoard()
{
    mBricks = std::vector<std::shared_ptr<Brick>>();
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            mBricks.push_back(std::make_shared<Brick>(Point(BOARD_PADDING + i * (BRICK_WIDTH), MARGIN_TOP + BOARD_PADDING + j * (BRICK_HEIGHT)), BRICK_WIDTH, BRICK_HEIGHT, BrickType::NORMAL, INITIAL_BRICK_HEALTH));
        }
    }
}

Board<eMapType::Basic>::Board<eMapType::Basic>()
{
    fillBasicBoard();
}

void Board<eMapType::Circular>::fillCircularBoard()
{
    mBricks = std::vector<std::shared_ptr<Brick>>();
    for (int i = 0; i < 360; i += 30)
    {
        // must be different layers from
        // the center of the circle
        mBricks.push_back(std::make_shared<Brick>(Point(512 + 100 * cos(i * M_PI / 180), 360 + 100 * sin(i * M_PI / 180)), 50, 20, BrickType::NORMAL, INITIAL_BRICK_HEALTH));
    }
}

Board<eMapType::Circular>::Board<eMapType::Circular>()
{
    fillCircularBoard();
}

void Board<eMapType::Basic>::reset()
{
    mBricks.clear();
    fillBasicBoard();
}

void Board<eMapType::Circular>::reset()
{
    mBricks.clear();
    fillCircularBoard();
}
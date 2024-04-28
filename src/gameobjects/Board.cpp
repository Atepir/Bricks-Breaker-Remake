#include "gameobjects/Board.hpp"

using namespace GameObjects;

std::vector<std::vector<BrickType>> readBricksFromFile(std::string pPath)
{
    std::vector<std::vector<BrickType>> bricks;
    std::ifstream file(pPath);
    try
    {
        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                std::vector<BrickType> row;
                for (char c : line)
                {
                    if (c == '\n' || c == ' ' || c == ',')
                    {
                        continue;
                    }
                    row.push_back(static_cast<BrickType>(c - '0'));
                }
                bricks.push_back(row);
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        // TODO: handle exception
    }

    return bricks;
}

void Board<eMapType::Basic>::fillBasicBoard(std::string pPath)
{
    if (mBricks.size() > 0)
    {
        mBricks.clear();
    }
    std::vector<std::vector<BrickType>> bricks = readBricksFromFile(pPath);
    mBricks = std::vector<std::shared_ptr<Brick>>();
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            mBricks.push_back(std::make_shared<Brick>(Point(BOARD_PADDING + i * BRICK_WIDTH, MARGIN_TOP + BOARD_PADDING + j * BRICK_HEIGHT), BRICK_WIDTH, BRICK_HEIGHT, bricks[j][i], INITIAL_BRICK_HEALTH));
        }
    }
}

Board<eMapType::Basic>::Board<eMapType::Basic>()
{
    fillBasicBoard(Resources::LevelManager::getCurrentLevelPath());
}

void Board<eMapType::Circular>::fillCircularBoard()
{
    mBricks = std::vector<std::shared_ptr<Brick>>();
    for (int i = 0; i < 360; i += 30)
    {
        // must be different layers from
        // the center of the circle
        mBricks.push_back(std::make_shared<Brick>(Point(512 + 100 * cos(i * M_PI / 180), 360 + 100 * sin(i * M_PI / 180)), 50, 20, BrickType::BRICK_BLUE, INITIAL_BRICK_HEALTH));
    }
}

Board<eMapType::Circular>::Board<eMapType::Circular>()
{
    fillCircularBoard();
}

void Board<eMapType::Basic>::reset()
{
    fillBasicBoard(Resources::LevelManager::getCurrentLevelPath());
}

void Board<eMapType::Circular>::reset()
{
    mBricks.clear();
    fillCircularBoard();
}
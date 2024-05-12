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
    std::shared_ptr<Graphics::Renderer> renderer = Graphics::Renderer::getInstance();
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
            int x = BOARD_PADDING + i * BRICK_WIDTH + renderer->getDeltaWidth() / 2;
            int y = MARGIN_TOP + BOARD_PADDING + j * BRICK_HEIGHT + renderer->getDeltaHeight() / 2;
            mBricks.push_back(std::make_shared<Brick>(Point(x, y), BRICK_WIDTH, BRICK_HEIGHT, bricks[j][i], INITIAL_BRICK_HEALTH, 0));
        }
    }
}

GameObjects::Board<eMapType::Basic>::Board<eMapType::Basic>()
{
    fillBasicBoard(Resources::LevelManager::getCurrentLevelPath());
}

void Board<eMapType::Circular>::fillCircularBoard(std::string pPath)
{
    std::shared_ptr<Graphics::Renderer> renderer = Graphics::Renderer::getInstance();

    if (mBricks.size() > 0)
    {
        mBricks.clear();
    }
    std::vector<std::vector<BrickType>> bricks = readBricksFromFile(pPath);
    mBricks = std::vector<std::shared_ptr<Brick>>();

    int angleDelta = 24;
    int emptyMiddleSize = 80;
    int lastPicked = 0;
    for (int i = 0; i < 360; i += angleDelta)
    {
        for (int j = 0; j < 4; j++)
        {
            double width = 38 + 10 * j;
            double x = 490 + (emptyMiddleSize + angleDelta * j) * cos(i * M_PI / 180) - j * 5 + renderer->getDeltaWidth() / 2;
            double y = 350 + (emptyMiddleSize + angleDelta * j) * sin(i * M_PI / 180) + renderer->getDeltaHeight() / 2;

            mBricks.push_back(std::make_shared<Brick>(Point(x, y), width, angleDelta, bricks[j][i / 24], INITIAL_BRICK_HEALTH, i + 90));
        }
    }
}

GameObjects::Board<eMapType::Circular>::Board<eMapType::Circular>()
{
    fillCircularBoard(Resources::LevelManager::getCurrentCircularLevelPath());
}

void Board<eMapType::Basic>::reset()
{
    fillBasicBoard(Resources::LevelManager::getCurrentLevelPath());
}

void Board<eMapType::Circular>::reset()
{
    fillCircularBoard(Resources::LevelManager::getCurrentCircularLevelPath());
}
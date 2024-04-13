#include "gameobjects/Board.hpp"

Board *Board::instance = nullptr;

Board *Board::getInstance(eMapType mapType)
{
    if (instance == nullptr)
    {
        instance = new Board(mapType);
    }
    return instance;
}

Board::Board(eMapType pMapType)
{
    mapType = pMapType;

    switch (mapType)
    {
    case eMapType::Basic:
    {
        bricks = std::vector<Brick *>();
        for (int i = 0; i < 18; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                bricks.push_back(new Brick(50 + i * 51, 50 + j * 21, 50, 20, BrickType::NORMAL, 1));
            }
        }
        break;
    }
    case eMapType::Circular:
    {
        bricks = std::vector<Brick *>();
        for (int i = 0; i < 360; i += 30)
        {
            // must be different layers from
            // the center of the circle
            bricks.push_back(new Brick(512 + 100 * cos(i * M_PI / 180), 360 + 100 * sin(i * M_PI / 180), 50, 20, BrickType::NORMAL, 1));
        }
        break;
    }
    default:
        break;
    }
}

Board::~Board()
{
    for (auto brick : bricks)
    {
        delete brick;
    }
}

void Board::update()
{
    for (auto brick : bricks)
    {
        brick->update(mapType);
    }
}

void Board::draw()
{
    for (auto brick : bricks)
    {
        brick->draw();
    }
}

void Board::collide(GameObject *other)
{
    for (auto brick : bricks)
    {
        brick->collide(other);
    }
}

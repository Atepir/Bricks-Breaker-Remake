#include "Board.hpp"

Board::Board() : GameObject()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            bricks.push_back(new Brick(50 + i * 50, 50 + j * 20, 50, 20, BrickType::NORMAL, 1));
        }
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
        brick->update();
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

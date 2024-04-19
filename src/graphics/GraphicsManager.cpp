#include "graphics/GraphicsManager.hpp"

void GraphicsManager<Basic>::update()
{
    Board<eMapType::Basic>::getInstance()->update();
    Paddle<eMapType::Basic>::getInstance()->update();
    SDL_RenderPresent(pRenderer);
};

void GraphicsManager<eMapType::Circular>::update()
{
    Board<eMapType::Circular>::getInstance()->update();
    Paddle<eMapType::Circular>::getInstance()->update();
    SDL_RenderPresent(pRenderer);
};

void GraphicsManager<eMapType::Basic>::draw()
{
    this->clear();
    SDL_Rect rect = {0, 0, 1024, 720};
    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);

    Board<eMapType::Basic>::getInstance()->draw();
    Paddle<eMapType::Basic>::getInstance()->draw();
}

void GraphicsManager<eMapType::Circular>::draw()
{
    this->clear();
    SDL_Rect rect = {0, 0, 1024, 720};
    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);

    Board<eMapType::Circular>::getInstance()->draw();
    Paddle<eMapType::Circular>::getInstance()->draw();
}
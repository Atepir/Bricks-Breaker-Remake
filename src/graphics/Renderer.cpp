#include "graphics/Renderer.hpp"

Renderer::Renderer(Game *pGame)
{
    mGame = pGame;
    mWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
}

void Renderer::clear()
{
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
    SDL_RenderClear(mRenderer);
}

void Renderer::render()
{
    SDL_RenderPresent(mRenderer);
}

SDL_Renderer *Renderer::getRenderer()
{
    return mRenderer;
}

void Renderer::draw(Texture *pTexture, Point pPosition)
{
    SDL_Rect dest;
    dest.x = pPosition.x;
    dest.y = pPosition.y;
    SDL_QueryTexture(pTexture->getTexture(), NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(mRenderer, pTexture->getTexture(), NULL, &dest);
}

void Renderer::draw(Texture *pTexture, Point pPosition, int pWidth, int pHeight)
{
    SDL_Rect dest;
    dest.x = pPosition.x;
    dest.y = pPosition.y;
    dest.w = pWidth;
    dest.h = pHeight;
    SDL_RenderCopy(mRenderer, pTexture->getTexture(), NULL, &dest);
}

void Renderer::drawRect(Point pPosition, int pWidth, int pHeight)
{
    SDL_Rect rect;
    rect.x = pPosition.x;
    rect.y = pPosition.y;
    rect.w = pWidth;
    rect.h = pHeight;
    SDL_RenderDrawRect(mRenderer, &rect);
}

void Renderer::drawRect(Point pPosition, int pWidth, int pHeight, int pR, int pG, int pB, int pA)
{
    SDL_SetRenderDrawColor(mRenderer, pR, pG, pB, pA);
    SDL_Rect rect;
    rect.x = pPosition.x;
    rect.y = pPosition.y;
    rect.w = pWidth;
    rect.h = pHeight;
    SDL_RenderFillRect(mRenderer, &rect);
}
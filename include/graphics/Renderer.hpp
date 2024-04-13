#ifndef __RENDERER_HPP
#define __RENDERER_HPP

#include <SDL.h>
#include <array>
#include <vector>

#include "geometry/Point.hpp"

class Renderer
{
private:
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;

public:
    Renderer();
    ~Renderer();

    void clear();
    void render();

    SDL_Renderer* getRenderer();

    void draw(SDL_Texture* pTexture, Point pPosition);
    void draw(SDL_Texture* pTexture, Point pPosition, int pWidth, int pHeight);

    void drawRect(Point pPosition, int pWidth, int pHeight);
    void drawRect(Point pPosition, int pWidth, int pHeight, int pR, int pG, int pB, int pA);
};

#endif
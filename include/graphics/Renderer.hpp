#ifndef __RENDERER_HPP__
#define __RENDERER_HPP__

#include <SDL.h>
#include <array>
#include <vector>

#include "geometry/Point.hpp"

class Texture;

class Renderer
{
    private:
        Game *mGame;
        SDL_Window *mWindow;
        SDL_Renderer *mRenderer;

    public:
        Renderer(Game *pGame);
        ~Renderer();

        void clear();
        void render();

        SDL_Renderer *getRenderer();

        void draw(Texture *pTexture, Point pPosition);
        void draw(Texture *pTexture, Point pPosition, int pWidth, int pHeight);

        void drawRect(Point pPosition, int pWidth, int pHeight);
        void drawRect(Point pPosition, int pWidth, int pHeight, int pR, int pG, int pB, int pA);
}


#endif
#ifndef __RENDERER_HPP
#define __RENDERER_HPP

#include <SDL.h>
#include <array>
#include <vector>

#include "geometry/Point.hpp"

class Texture;
class Game;

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

#include "graphics/Texture.hpp";
#include "Game.hpp";

#endif
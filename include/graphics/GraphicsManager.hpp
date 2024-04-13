#ifndef __GRAPHICS_HPP
#define __GRAPHICS_HPP

#include <SDL.h>
#include <iostream>

#include "gameobjects/Paddle.hpp"
#include "gameobjects/Board.hpp"
#include "resources/Enums.hpp"

class Graphics
{
protected:
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
    eMapType mapType;

    static Graphics *pInstance;

public:
    Graphics(eMapType pMapType);

    Graphics(const Graphics &) = delete;
    void operator=(const Graphics &) = delete;

    static Graphics *getInstance();

    ~Graphics();
    void init();
    void update();
    void clear();
    void draw();
    void quit();

    SDL_Texture *loadTexture(const char *pFilename);

    SDL_Renderer *getRenderer();
};

#endif // __GRAPHICS_HPP

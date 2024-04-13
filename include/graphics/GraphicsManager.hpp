#ifndef __GRAPHICS_MANAGER_HPP
#define __GRAPHICS_MANAGER_HPP

#include <SDL.h>
#include <iostream>

#include "gameobjects/Paddle.hpp"
#include "gameobjects/Board.hpp"
#include "resources/Enums.hpp"

class GraphicsManager
{
protected:
    SDL_Window *pWindow;
    SDL_Renderer *pRenderer;
    eMapType mapType;

    static GraphicsManager *pInstance;

public:
    GraphicsManager(eMapType pMapType);

    GraphicsManager(const GraphicsManager &) = delete;
    void operator=(const GraphicsManager &) = delete;

    static GraphicsManager *getInstance();

    ~GraphicsManager();
    void init();
    void update();
    void clear();
    void draw();
    void quit();

    SDL_Texture *loadTexture(const char *pFilename);

    SDL_Renderer *getRenderer();
};

#endif // __GRAPHICS_MANAGER_HPP

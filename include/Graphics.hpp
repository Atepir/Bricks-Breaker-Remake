#ifndef __GRAPHICS_HPP
#define __GRAPHICS_HPP

#include <SDL.h>
#include <iostream>

#include "Paddle.hpp"

class Graphics
{
protected:
    SDL_Window* pWindow;
    SDL_Renderer* pRenderer;

    static Graphics* pInstance;

public:
    Graphics();

    Graphics(const Graphics&) = delete;
    void operator=(const Graphics&) = delete;

    static Graphics* getInstance();

    ~Graphics();
    void init();
    void update();
    void clear();
    void draw();
    void quit();

    SDL_Texture* loadTexture(const char* pFilename);

    SDL_Renderer* getRenderer();
};

#endif // __GRAPHICS_HPP

#ifndef __GRAPHICS_HPP
#define __GRAPHICS_HPP

#include <SDL2/SDL.h>
#include <iostream>

class Graphics
{
protected:
    SDL_Window *pWindow = nullptr;
    SDL_Surface *pSurface = nullptr;
    SDL_Renderer *pRenderer = nullptr;

    static Graphics *pInstance;

public:
    Graphics();

    // non cloneable
    Graphics(const Graphics &) = delete;
    // non assignable
    void operator=(const Graphics &) = delete;

    static Graphics *getInstance();

    ~Graphics();
    void init();
    void update();
    void clear();
    void draw();
    void quit();

    SDL_Renderer *getRenderer();
};

#endif // __GRAPHICS_HPP
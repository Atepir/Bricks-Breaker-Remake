#ifndef __GRAPHICS_MANAGER_HPP
#define __GRAPHICS_MANAGER_HPP

#include <SDL.h>

#include <iostream>

#include "geometry/Point.hpp"
#include "resources/Enums.hpp"

using namespace Geometry;

namespace Graphics
{
    class GraphicsManager
    {
    protected:
        SDL_Window *pWindow;
        SDL_Renderer *pRenderer;

        static inline GraphicsManager *pInstance = nullptr;

    public:
        GraphicsManager();

        GraphicsManager(const GraphicsManager &) = delete;
        void operator=(const GraphicsManager &) = delete;

        static GraphicsManager *getInstance()
        {
            if (pInstance == nullptr)
            {
                pInstance = new GraphicsManager();
            }
            return pInstance;
        }

        ~GraphicsManager()
        {
            quit();
        }

        void init()
        {
            if (SDL_Init(SDL_INIT_VIDEO) != 0)
            {
                std::cerr << "Failed to initialize SDL " << SDL_GetError() << std::endl;
                exit(1);
            }

            pWindow = SDL_CreateWindow("BricksBreaker Remake!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 720, SDL_WINDOW_SHOWN);
            if (pWindow == nullptr)
            {
                std::cerr << "Failed to create window " << SDL_GetError() << std::endl;
                exit(1);
            }

            pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (pRenderer == nullptr)
            {
                std::cerr << "Failed to create renderer for window " << SDL_GetError() << std::endl;
                exit(1);
            }
        }

        void clear()
        {
            SDL_RenderClear(pRenderer);
        }

        void quit()
        {
            SDL_DestroyRenderer(pRenderer);
            SDL_DestroyWindow(pWindow);
            SDL_Quit();
        }

        void draw(SDL_Texture *pTexture, Point pPosition, double pWidth, double pHeight, double pAngle)
        {
            SDL_Rect destRect = {pPosition.x, pPosition.y, pWidth, pHeight};
            SDL_RenderCopyEx(pRenderer, pTexture, NULL, &destRect, pAngle, NULL, SDL_FLIP_NONE);
        }

        void render()
        {
            SDL_RenderPresent(pRenderer);
        }

        SDL_Renderer *getRenderer()
        {
            return pRenderer;
        }
    };
}

#endif // __GRAPHICS_MANAGER_HPP

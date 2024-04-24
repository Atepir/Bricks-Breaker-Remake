#ifndef __GRAPHICS_MANAGER_HPP
#define __GRAPHICS_MANAGER_HPP

#include <SDL.h>

#include <iostream>

#include "geometry/Point.hpp"
#include "resources/Enums.hpp"
#include "graphics/Font.hpp"

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

            pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
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
            SDL_RenderCopyEx(*Graphics::GraphicsManager::getInstance()->getRenderer(), pTexture, NULL, &destRect, pAngle, NULL, SDL_FLIP_NONE);
        }

        void drawRect(int x, int y, int w, int h)
        {
            SDL_Rect rect = {x, y, w, h};
            SDL_SetRenderDrawColor(*Graphics::GraphicsManager::getInstance()->getRenderer(), 255, 255, 255, 255);
            SDL_RenderFillRect(*Graphics::GraphicsManager::getInstance()->getRenderer(), &rect);
        }

        void drawText(Font *font, int x, int y)
        {
            SDL_Rect dest;

            dest.x = x;
            dest.y = y;
            dest.w = font->getWidth();
            dest.h = font->getHeight();
            std::cout << "Drawing text at " << x << ", " << y << " with width " << font->getWidth() << " and height " << font->getHeight() << " and texture " << font->getTexture() << std::endl;

            SDL_RenderCopy(*Graphics::GraphicsManager::getInstance()->getRenderer(), font->getTexture(), NULL, &dest);
        }

        void render()
        {
            SDL_RenderPresent(pRenderer);
        }

        std::unique_ptr<SDL_Renderer *> getRenderer() const
        {
            std::cout << "Returning renderer " << pRenderer << std::endl;
            return std::make_unique<SDL_Renderer *>(pRenderer);
        }
    };
}

#endif // __GRAPHICS_MANAGER_HPP

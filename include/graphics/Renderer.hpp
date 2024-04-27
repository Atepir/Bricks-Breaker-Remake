#ifndef __RENDERER_HPP
#define __RENDERER_HPP

#include <SDL.h>

#include <iostream>

#include "geometry/Point.hpp"
#include "resources/Enums.hpp"
#include "graphics/Font.hpp"

using namespace Geometry;

namespace Graphics
{
    using Type_SDL_Renderer = SDL_Renderer *;
    using Type_SDL_Window = SDL_Window *;

    class Renderer
    {
    protected:
        Type_SDL_Window pWindow;
        Type_SDL_Renderer pRenderer;

        static inline std::shared_ptr<Renderer> pInstance = nullptr;

    public:
        Renderer() : pWindow(nullptr), pRenderer(nullptr) {}

        Renderer(const Renderer &) = delete;
        void operator=(const Renderer &) = delete;

        static std::shared_ptr<Renderer> getInstance()
        {
            if (pInstance == nullptr)
            {
                pInstance = std::make_shared<Renderer>();
            }
            return pInstance;
        }

        ~Renderer()
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

            SDL_SetRenderDrawBlendMode(pRenderer, SDL_BLENDMODE_BLEND);
            SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 0);
        }

        void clear()
        {
            SDL_SetRenderDrawBlendMode(pRenderer, SDL_BLENDMODE_BLEND);
            SDL_RenderClear(pRenderer);
        }

        void quit()
        {
            SDL_DestroyRenderer(pRenderer);
            SDL_DestroyWindow(pWindow);
            SDL_Quit();
        }

        void draw(Type_SDL_Texture pTexture, Point pPosition, double pWidth, double pHeight, double pAngle)
        {
            // std::cout << "Drawing texture " << pTexture << " at " << pPosition.x << ", " << pPosition.y << " with width " << pWidth << " and height " << pHeight << " and angle " << pAngle << std::endl;
            // std::cout << "IN DRAW - Renderer: " << pRenderer << std::endl;
            SDL_Rect destRect = {pPosition.x, pPosition.y, pWidth, pHeight};
            // make sure to render with transparent background
            SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 0);
            SDL_RenderCopyEx(Graphics::Renderer::getInstance()->getRenderer(), pTexture, NULL, &destRect, pAngle, NULL, SDL_FLIP_NONE);
        }

        void drawRect(int x, int y, int w, int h)
        {
            SDL_Rect rect = {x, y, w, h};
            SDL_SetRenderDrawColor(Graphics::Renderer::getInstance()->getRenderer(), 255, 255, 255, 255);
            SDL_RenderFillRect(Graphics::Renderer::getInstance()->getRenderer(), &rect);
        }

        void drawText(Font font, int x, int y, int width, int height)
        {
            SDL_Rect dest;

            dest.x = x;
            dest.y = y;
            dest.w = width;
            dest.h = height;
            // std::cout << "Drawing text at " << x << ", " << y << " with width " << width << " and height " << height << " and texture " << font.getTexture() << std::endl;

            SDL_RenderCopy(Graphics::Renderer::getInstance()->getRenderer(), font.getTexture(), NULL, &dest);
        }

        void render()
        {
            SDL_RenderPresent(pRenderer);
        }

        Type_SDL_Renderer getRenderer() const
        {
            // std::cout << "Returning renderer " << pRenderer << std::endl;
            return pRenderer;
        }
    };
}

#endif // __GRAPHICS_MANAGER_HPP

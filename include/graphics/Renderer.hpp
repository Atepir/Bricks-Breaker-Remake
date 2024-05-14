#ifndef __RENDERER_HPP
#define __RENDERER_HPP

#include <SDL.h>
#include <SDL_ttf.h>

#include <iostream>

#include "geometry/Point.hpp"
#include "resources/Enums.hpp"
#include "resources/Constants.hpp"
#include "graphics/Font.hpp"

using namespace Geometry;

namespace Graphics
{
    using Type_SDL_Renderer = SDL_Renderer *;
    using Type_SDL_Window = SDL_Window *;

    /**
     * @brief Manages the rendering of the game.
     * @details This class is a singleton and is responsible for initializing the SDL library, creating the window and renderer, and rendering the game.
     */
    class Renderer
    {
    protected:
        Type_SDL_Window pWindow;
        Type_SDL_Renderer pRenderer;

        static inline std::shared_ptr<Renderer> pInstance = nullptr;

    private:
        int mScreenWidth;
        int mScreenHeight;

    public:
        Renderer() : pWindow(nullptr), pRenderer(nullptr), mScreenWidth(WINDOW_WIDTH), mScreenHeight(WINDOW_HEIGHT) {}

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

            pWindow = SDL_CreateWindow("BricksBreaker Remake!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mScreenWidth, mScreenHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
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

            if (TTF_Init() == -1)
            {
                std::cerr << "Failed to initialize SDL_ttf " << TTF_GetError() << std::endl;
                exit(1);
            }

            Type_TTF_Font font = TTF_OpenFont("font.ttf", 64);
            if (font == nullptr)
            {
                std::cerr << "Failed to load font.ttf" << std::endl;
                std::cerr << TTF_GetError() << std::endl;
            }
            Font::setDefaultFont(font);
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
            TTF_Quit();
            SDL_Quit();
        }

        void draw(Type_SDL_Texture pTexture, Point pPosition, double pWidth, double pHeight, double pAngle)
        {
            SDL_Rect destRect = {pPosition.x, pPosition.y, pWidth, pHeight};
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

            Type_SDL_Texture texture = SDL_CreateTextureFromSurface(pRenderer, font.getSurface());

            SDL_RenderCopy(Graphics::Renderer::getInstance()->getRenderer(), texture, NULL, &dest);
        }

        void render()
        {
            SDL_RenderPresent(pRenderer);
            SDL_GetWindowSize(pWindow, &mScreenWidth, &mScreenHeight);
        }

        Type_SDL_Renderer getRenderer() const
        {
            return pRenderer;
        }

        int getScreenWidth() const
        {
            return mScreenWidth;
        }

        int getScreenHeight() const
        {
            return mScreenHeight;
        }

        int getDeltaWidth() const
        {
            if (mScreenWidth > WINDOW_WIDTH)
                return mScreenWidth - WINDOW_WIDTH;
            return 0;
        }

        int getDeltaHeight() const
        {
            if (mScreenHeight > WINDOW_HEIGHT)
                return mScreenHeight - WINDOW_HEIGHT;
            return 0;
        }
    };
}

#endif // __GRAPHICS_MANAGER_HPP

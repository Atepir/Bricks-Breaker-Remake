#ifndef __FONT_HPP
#define __FONT_HPP

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

#include "resources/Enums.hpp"

#include <iostream>

namespace Graphics
{
    class GraphicsManager;

    class Font
    {
    private:
        static inline TTF_Font *defaultFont = nullptr;
        static inline TTF_Font *defaultBigFont = nullptr;
        std::string text;
        int width = 600, height = 100;
        TTF_Font *font;
        SDL_Texture *texture;

    public:
        Font() = default;
        Font(std::string text, eColor pColor);
        ~Font();

        std::string getText() const;
        void setText(std::string text, eColor pColor);
        SDL_Texture *getTexture() const;

        int getWidth() const { return width; }
        int getHeight() const { return height; }

        static void setDefaultFonts(TTF_Font *small, TTF_Font *large);
    };
}

#include "graphics/GraphicsManager.hpp"

#endif
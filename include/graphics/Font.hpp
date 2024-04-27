#ifndef __FONT_HPP
#define __FONT_HPP

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

#include "resources/Enums.hpp"

#include <iostream>

namespace Graphics
{
    class Renderer;

    using Type_TTF_Font = TTF_Font *;
    using Type_SDL_Texture = SDL_Texture *;
    using Type_SDL_Surface = SDL_Surface *;

    class Font
    {
    private:
        static inline Type_TTF_Font defaultFont = nullptr;
        std::string text;
        int width = 600, height = 100;
        Type_TTF_Font font;
        Type_SDL_Texture texture;

    public:
        Font() = default;
        Font(std::string text, eColor pColor);
        ~Font();

        std::string getText() const;
        void setText(std::string text, eColor pColor);

        Type_SDL_Texture getTexture() const;

        int getWidth() const { return width; }
        int getHeight() const { return height; }

        static void setDefaultFont(Type_TTF_Font pFont);
    };
}

#include "graphics/Renderer.hpp"

#endif
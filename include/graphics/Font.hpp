#ifndef __FONT_HPP
#define __FONT_HPP

#include <iostream>
#include <map>

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

#include "resources/Enums.hpp"

#ifndef make_color
#define make_color(r, g, b) \
    SDL_Color { r, g, b }
#endif

namespace Graphics
{
    using Type_TTF_Font = TTF_Font *;
    using Type_SDL_Texture = SDL_Texture *;
    using Type_SDL_Surface = SDL_Surface *;

    /**
     * @brief Represents a font
     */
    class Font
    {
    private:
        static inline Type_TTF_Font mDefaultFont = nullptr;
        std::string mText;
        int mWidth = 600, mHeight = 100;
        Type_TTF_Font mFont;
        Type_SDL_Surface mSurface;
        static inline std::map<int, SDL_Color> mColors = {
            {0, make_color(0xff, 0xff, 0xff)},
            {1, make_color(0x00, 0x00, 0x00)},
            {2, make_color(0xff, 0x00, 0x00)},
            {3, make_color(0x00, 0xff, 0x00)},
            {4, make_color(0x00, 0x00, 0xff)},
            {5, make_color(0xff, 0xff, 0x00)},
            {6, make_color(0x00, 0xff, 0xff)},
            {7, make_color(0xff, 0x00, 0xff)}};

    public:
        Font() {}

        Font(std::string text, eColor pColor) : mText(text), mWidth(100), mHeight(10)
        {
            mFont = std::move(mDefaultFont);
            mSurface = TTF_RenderUTF8_Blended(mFont, text.c_str(), mColors[pColor]);
        }
        ~Font() {}

        inline std::string getText() const { return mText; }

        inline void setText(std::string pText, eColor pColor)
        {
            this->mText = pText;
            mSurface = TTF_RenderUTF8_Blended(mFont, this->mText.c_str(), mColors[pColor]);
        }

        Type_SDL_Surface getSurface() const { return mSurface; }

        inline int getWidth() const { return mWidth; }
        inline int getHeight() const { return mHeight; }

        static inline void setDefaultFont(Type_TTF_Font pFont) { mDefaultFont = pFont; }
    };
}

#endif
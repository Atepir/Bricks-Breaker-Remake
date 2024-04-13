#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__

#indlude <SDL.h>
#include <iostream>

#include "graphics/Renderer.hpp"
#include "geometry/Point.hpp"

class Texture
{
    private:
        std::string mFilename;
        SDL_Texture *mTexture;
        Point mPosition;

    public:
        Texture(Renderer *pRenderer, const std::string &pFilename);
        ~Texture();

        SDL_Texture *getTexture();

        Point getPosition() const;
};

#endif
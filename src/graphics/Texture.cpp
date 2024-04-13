#include "graphics/Texture.hpp"

Texture::Texture(Renderer *pRenderer, const std::string &pFilename)
{
    mFilename = pFilename;
    mTexture = IMG_LoadTexture(pRenderer->getRenderer(), pFilename.c_str());
    if (mTexture == nullptr)
    {
        std::cerr << "Failed to load texture: " << pFilename << std::endl;
    }
}

Texture::~Texture()
{
    SDL_DestroyTexture(mTexture);
}

SDL_Texture *Texture::getTexture()
{
    return mTexture;
}

Point Texture::getPosition() const
{
    return mPosition;
}


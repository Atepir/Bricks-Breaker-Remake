#include "resources/ResourceManager.hpp"

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
    for (auto &texture : mTextures)
    {
        delete texture.second;
    }
}

void ResourceManager::addTexture(const std::string &pName, SDL_Texture *pTexture)
{
    mTextures[pName] = pTexture;
}

SDL_Texture *ResourceManager::getTexture(const std::string &pName)
{
    return mTextures[pName];
}

void ResourceManager::loadTextures()
{
    // one texture file from which to load textures
    SDL_Surface *pSurface = SDL_LoadBMP("assets/spritesheet.bmp");
    if (pSurface == nullptr)
    {
        std::cerr << "Failed to load image " << "assets/spritesheet.png" << " " << SDL_GetError() << std::endl;
        exit(1);
    }

    // load the textures
    // paddle
    SDL_Rect rect = {0, 0, 64, 16};
    SDL_Surface *pPaddleSurface = SDL_CreateRGBSurface(0, 64, 16, 32, 0, 0, 0, 0);
    SDL_BlitSurface(pSurface, &rect, pPaddleSurface, NULL);
    SDL_Texture *pPaddleTexture = SDL_CreateTextureFromSurface(GraphicsManager::getInstance()->getRenderer(), pPaddleSurface);
    addTexture("paddle", pPaddleTexture);

    // ball
    rect = {0, 16, 16, 16};
    SDL_Surface *pBallSurface = SDL_CreateRGBSurface(0, 16, 16, 32, 0, 0, 0, 0);
    SDL_BlitSurface(pSurface, &rect, pBallSurface, NULL);
    SDL_Texture *pBallTexture = SDL_CreateTextureFromSurface(GraphicsManager::getInstance()->getRenderer(), pBallSurface);
    addTexture("ball", pBallTexture);

    // brick
    rect = {0, 32, 64, 16};
    SDL_Surface *pBrickSurface = SDL_CreateRGBSurface(0, 64, 16, 32, 0, 0, 0, 0);
    SDL_BlitSurface(pSurface, &rect, pBrickSurface, NULL);
    SDL_Texture *pBrickTexture = SDL_CreateTextureFromSurface(GraphicsManager::getInstance()->getRenderer(), pBrickSurface);
    addTexture("brick", pBrickTexture);
}

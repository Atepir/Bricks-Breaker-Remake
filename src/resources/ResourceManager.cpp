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

void ResourceManager::addTexture(const std::string &pName, Texture *pTexture)
{
    mTextures[pName] = pTexture;
}

Texture *ResourceManager::getTexture(const std::string &pName)
{
    return mTextures[pName];
}

void ResourceManager::loadTextures()
{
    // one texture file from which to load textures
    SDL_Surface *pSurface = IMG_Load("assets/spritesheet.png");
    if (pSurface == nullptr)
    {
        std::cerr << "Failed to load image " << "assets/spritesheet.png" << " " << IMG_GetError() << std::endl;
        exit(1);
    }

    // load the textures
    // paddle
    SDL_Rect rect = {0, 0, 64, 16};
    SDL_Surface *pPaddleSurface = SDL_CreateRGBSurface(0, 64, 16, 32, 0, 0, 0, 0);
    SDL_BlitSurface(pSurface, &rect, pPaddleSurface, NULL);
    Texture *pPaddleTexture = new Texture(SDL_CreateTextureFromSurface(GraphicsManager::getInstance()->getRenderer(), pPaddleSurface));
    addTexture("paddle", pPaddleTexture);

    // ball
    rect = {0, 16, 16, 16};
    SDL_Surface *pBallSurface = SDL_CreateRGBSurface(0, 16, 16, 32, 0, 0, 0, 0);
    SDL_BlitSurface(pSurface, &rect, pBallSurface, NULL);
    Texture *pBallTexture = new Texture(SDL_CreateTextureFromSurface(GraphicsManager::getInstance()->getRenderer(), pBallSurface));
    addTexture("ball", pBallTexture);

    // brick
    rect = {0, 32, 64, 16};
    SDL_Surface *pBrickSurface = SDL_CreateRGBSurface(0, 64, 16, 32, 0, 0, 0, 0);
    SDL_BlitSurface(pSurface, &rect, pBrickSurface, NULL);
    Texture *pBrickTexture = new Texture(SDL_CreateTextureFromSurface(GraphicsManager::getInstance()->getRenderer(), pBrickSurface));
    addTexture("brick", pBrickTexture);
}

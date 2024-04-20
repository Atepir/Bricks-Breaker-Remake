#include "resources/ResourceManager.hpp"

ResourceManager *ResourceManager::pInstance = nullptr;

ResourceManager *ResourceManager::getInstance()
{
    if (pInstance == nullptr)
    {
        pInstance = new ResourceManager();
        pInstance->loadTextures();
    }
    return pInstance;
}

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

std::string ResourceManager::brickTypeToString(BrickType pType)
{
    switch (pType)
    {
    case BrickType::NORMAL:
        return "normal";
    case BrickType::UNBREAKABLE:
        return "unbreakable";
    default:
        return "";
    }
}

std::string ResourceManager::ballTypeToString(BallType pType)
{
    switch (pType)
    {
    case BallType::NORMAL:
        return "normal";
    case BallType::EXPLOSIVE:
        return "explosive";
    default:
        return "";
    }
}

void ResourceManager::addTexture(const std::string &pName, SDL_Texture *pTexture)
{
    mTextures[pName] = pTexture;
}

void ResourceManager::addTexture(const std::string &pName, SDL_Rect &pRect, SDL_Surface *pSurface, SDL_Surface *pTextureSurface, SDL_Rect *pDestRect)
{
    if (pDestRect == NULL)
        SDL_BlitSurface(pSurface, &pRect, pTextureSurface, NULL);
    else
        SDL_BlitScaled(pSurface, &pRect, pTextureSurface, pDestRect);
    SDL_Texture *pTexture = SDL_CreateTextureFromSurface(GraphicsManager::getInstance()->getRenderer(), pTextureSurface);
    addTexture(pName, pTexture);
}

SDL_Texture *ResourceManager::getTexture(const string &pName)
{
    return mTextures[pName];
}

SDL_Texture *ResourceManager::getTexture(const string &pName, BrickType type)
{
    string name = pName + "_" + ResourceManager::getInstance()->brickTypeToString(type);
    return ResourceManager::getInstance()->getTexture(name);
}

SDL_Texture *ResourceManager::getTexture(const string &pName, BallType type)
{
    string name = pName + "_" + ResourceManager::getInstance()->ballTypeToString(type);
    return ResourceManager::getInstance()->getTexture(name);
}

void ResourceManager::loadTextures()
{
    // one texture file from which to load textures
    SDL_Surface *pSurface = SDL_LoadBMP("set.bmp");
    if (pSurface == nullptr)
    {
        std::cerr << "Failed to load image "
                  << "set.bmp"
                  << " " << SDL_GetError() << std::endl;
        exit(1);
    }

    // load the textures
    // paddle
    SDL_Rect paddleRect = {500, 16, 212, 70};
    SDL_Surface *paddleSurface = SDL_CreateRGBSurface(0, 212, 70, 32, 0, 0, 0, 0);
    SDL_Rect destRect = {10, 10, 212, 70};
    addTexture("paddle_basic", paddleRect, pSurface, paddleSurface, &destRect);

    // bricks
    SDL_Rect brickRect = {22, 18, 226, 80};
    SDL_Surface *brickSurface = SDL_CreateRGBSurface(0, 236, 86, 32, 0, 0, 0, 0);
    destRect = {10, 10, 226, 80};
    addTexture("brick_normal", brickRect, pSurface, brickSurface, &destRect);

    // ball
    SDL_Rect ballRect = {1026, 700, 115, 115};
    SDL_Surface *ballSurface = SDL_CreateRGBSurface(0, 115, 115, 32, 0, 0, 0, 0);
    destRect = {10, 10, 115, 115};
    addTexture("ball_normal", ballRect, pSurface, ballSurface, &destRect);

    std::cout << "Textures loaded" << std::endl;
    std::cout << "paddle_basic: " << mTextures["paddle_basic"] << std::endl;
}

#ifndef __RESOURCE_MANAGER_HPP
#define __RESOURCE_MANAGER_HPP

#include "SDL.h"

#include <unordered_map>
#include <vector>
#include <iostream>

#include "resources/Enums.hpp"

class GraphicsManager;

using namespace std;

class ResourceManager
{
private:
    unordered_map<string, SDL_Texture *> mTextures;

    void loadTextures();

    static ResourceManager *pInstance;

public:
    ResourceManager();

    static ResourceManager *getInstance();

    ResourceManager(const ResourceManager &) = delete;
    ResourceManager &operator=(const ResourceManager &) = delete;

    ~ResourceManager();

    void addTexture(const string &pName, SDL_Texture *pTexture);
    void addTexture(const string &pName, SDL_Rect &pRect, SDL_Surface *pSurface, SDL_Surface *pTextureSurface, SDL_Rect *pDestRect);
    SDL_Texture *getTexture(const string &pName);
    SDL_Texture *getTexture(const string &pName, BrickType type);
    SDL_Texture *getTexture(const string &pName, BallType type);

    std::string brickTypeToString(BrickType pType);
    std::string ballTypeToString(BallType pType);
};

#include "graphics/GraphicsManager.hpp"

#endif
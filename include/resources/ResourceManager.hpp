#ifndef __RESOURCE_MANAGER_HPP
#define __RESOURCE_MANAGER_HPP

#include <unordered_map>
#include <vector>


class GraphicsManager;

class ResourceManager
{
    private:
        std::unordered_map<std::string, SDL_Texture *> mTextures;

        void loadTextures();

    public:
        ResourceManager();
        ~ResourceManager();

        void addTexture(const std::string &pName, SDL_Texture *pTexture);
        SDL_Texture *getTexture(const std::string &pName);
};

#include "graphics/GraphicsManager.hpp"

#endif
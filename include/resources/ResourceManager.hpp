#ifndef __RESOURCE_MANAGER_HPP
#define __RESOURCE_MANAGER_HPP

#include <unordered_map>
#include <vector>

#include "graphics/Texture.hpp"

class GraphicsManager;

class ResourceManager
{
    private:
        std::unordered_map<std::string, Texture *> mTextures;

        void loadTextures();

    public:
        ResourceManager();
        ~ResourceManager();

        void addTexture(const std::string &pName, Texture *pTexture);
        Texture *getTexture(const std::string &pName);
};

#include "graphics/GraphicsManager.hpp"

#endif
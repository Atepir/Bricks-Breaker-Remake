#ifndef __RESOURCE_MANAGER_HPP
#define __RESOURCE_MANAGER_HPP

#include <unordered_map>
#include <vector>
#include <iostream>

#include "resources/Enums.hpp"

#include "graphics/TextureHelper.hpp"
#include "graphics/Texture.hpp"

using namespace std;

namespace Resources
{
    class ResourceManager
    {
    private:
        unordered_map<eTextureKey, Graphics::Texture> mTextures;

        void loadTextures();

        static std::shared_ptr<ResourceManager> pInstance;

    public:
        ResourceManager();

        static std::shared_ptr<ResourceManager> getInstance();

        ResourceManager(const ResourceManager &) = delete;
        ResourceManager &operator=(const ResourceManager &) = delete;

        ~ResourceManager();

        /**
         * @brief Adds a texture to the resource manager
         * @param pTexture
         */
        void addTexture(const eTextureKey &pTextureKey, Graphics::Texture pTexture);

        /**
         * @brief Gets a texture from the resource manager
         * @param pTextureKey
         * @return Graphics::Texture
         */
        Graphics::Texture getTexture(const eTextureKey &pTextureKey);
    };
}

#endif
#include "resources/ResourceManager.hpp"

using namespace Resources;

std::shared_ptr<ResourceManager> ResourceManager::pInstance = nullptr;

std::shared_ptr<ResourceManager> ResourceManager::getInstance()
{
    if (pInstance == nullptr)
    {
        pInstance = std::make_shared<ResourceManager>();
        pInstance->loadTextures();
    }
    return pInstance;
}

ResourceManager::ResourceManager()
{
    mTextures = std::unordered_map<eTextureKey, std::shared_ptr<Graphics::Texture>>();
}

ResourceManager::~ResourceManager()
{
}

void ResourceManager::addTexture(const eTextureKey &pTextureKey, std::shared_ptr<Graphics::Texture> pTexture)
{
    mTextures[pTextureKey] = pTexture;
}

std::shared_ptr<Graphics::Texture> ResourceManager::getTexture(const eTextureKey &pTextureKey)
{
    return mTextures[pTextureKey];
}

void ResourceManager::loadTextures()
{
    std::shared_ptr<Graphics::TextureHelper> textureHelper = std::make_shared<Graphics::TextureHelper>();
    textureHelper->loadTileset("set.bmp");

    // load the textures
    // paddles
    addTexture(eTextureKey::Texture_Paddle_Basic,
               textureHelper->loadTexture("paddle_basic", 500, 16, 212, 70, 0, 0, 212, 70));

    // bricks
    addTexture(eTextureKey::Texture_Brick_Normal,
               textureHelper->loadTexture("brick_normal", 26, 22, 214, 72, 0, 0, 214, 72));

    // balls
    addTexture(eTextureKey::Texture_Ball_Basic,
               textureHelper->loadTexture("ball_normal", 1032, 700, 115, 115, 0, 0, 115, 115));

    // Graphics::Renderer::getInstance()->draw(getTexture(eTextureKey::Texture_Paddle_Basic)->getTexture(), {50, 50}, 100, 50, 0);
    // Graphics::Renderer::getInstance()->render();

    // heart
    addTexture(eTextureKey::Texture_Heart,
               textureHelper->loadTexture("heart", 1032, 590, 115, 115, 0, 0, 115, 115));

    // Backgrounds
    addTexture(eTextureKey::Texture_Main_Menu_Background,
               Graphics::TextureHelper::loadTexture("main_menu_background.bmp", "main_menu_background"));

    // std::cout << "Textures loaded" << std::endl;
    // std::cout << "Number of textures loaded: " << mTextures.size() << std::endl;

    // for (auto &texture : mTextures)
    // {
    //     std::cout << texture.second << std::endl;
    // }
}

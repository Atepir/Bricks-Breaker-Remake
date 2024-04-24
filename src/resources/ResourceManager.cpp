#include "resources/ResourceManager.hpp"

using namespace Resources;

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
    mTextures = std::unordered_map<eTextureKey, Graphics::Texture *>();
}

ResourceManager::~ResourceManager()
{
    for (auto &texture : mTextures)
    {
        texture.second->~Texture();
    }
}

void ResourceManager::addTexture(const eTextureKey &pTextureKey, Graphics::Texture *pTexture)
{
    mTextures[pTextureKey] = pTexture;
}

Graphics::Texture *ResourceManager::getTexture(const eTextureKey &pTextureKey)
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
               textureHelper->loadTexture("paddle_basic", 500, 16, 212, 70, 10, 10, 212, 70));

    // bricks
    addTexture(eTextureKey::Texture_Brick_Normal,
               textureHelper->loadTexture("brick_normal", 22, 18, 226, 80, 10, 10, 226, 80));

    // balls
    addTexture(eTextureKey::Texture_Ball_Basic,
               textureHelper->loadTexture("ball_normal", 1026, 700, 115, 115, 10, 10, 115, 115));

    // Graphics::GraphicsManager::getInstance()->draw(getTexture(eTextureKey::Texture_Paddle_Basic)->getTexture(), {50, 50}, 100, 50, 0);
    // Graphics::GraphicsManager::getInstance()->render();

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

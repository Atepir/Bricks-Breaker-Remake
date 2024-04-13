#include "graphics/GraphicsManager.hpp"

GraphicsManager *GraphicsManager::pInstance = nullptr;
SDL_Renderer *pRenderer_copy = nullptr;

GraphicsManager *GraphicsManager::getInstance()
{
    if (pInstance == nullptr)
    {
        pInstance = new GraphicsManager(eMapType::Basic);
    }
    return pInstance;
}

GraphicsManager::GraphicsManager(eMapType pMapType)
{
    pWindow = nullptr;
    pRenderer = nullptr;
    mapType = pMapType;
}

GraphicsManager::~GraphicsManager()
{
    quit();
}

void GraphicsManager::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Failed to initialize SDL " << SDL_GetError() << std::endl;
        exit(1);
    }

    pWindow = SDL_CreateWindow("BricksBreaker Remake!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 720, SDL_WINDOW_SHOWN);
    if (pWindow == nullptr)
    {
        std::cerr << "Failed to create window " << SDL_GetError() << std::endl;
        exit(1);
    }

    pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (pRenderer == nullptr)
    {
        std::cerr << "Failed to create renderer for window " << SDL_GetError() << std::endl;
        exit(1);
    }
    pRenderer_copy = pRenderer;
}

void GraphicsManager::update()
{
    Paddle::getInstance()->update(mapType);
    Board::getInstance(mapType)->update();
    SDL_RenderPresent(pRenderer);
}

void GraphicsManager::clear()
{
    SDL_RenderClear(pRenderer);
}

void GraphicsManager::draw()
{
    SDL_Rect rect = {0, 0, 1024, 720};
    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
    Paddle::getInstance()->draw(mapType);
    Board::getInstance(mapType)->draw();
}

void GraphicsManager::quit()
{
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
}

SDL_Texture *GraphicsManager::loadTexture(const char *pFilename)
{
    SDL_Surface *pSurface = SDL_LoadBMP(pFilename);
    if (pSurface == nullptr)
    {
        std::cerr << "Failed to load image " << pFilename << " " << SDL_GetError() << std::endl;
        exit(1);
    }

    SDL_Texture *pTexture = nullptr;

    if (pRenderer == nullptr)
    {
        // std::cerr << "pRenderer is null " << SDL_GetError() << std::endl;
        if (pRenderer_copy == nullptr)
        {
            std::cerr << "pRenderer_copy is null " << SDL_GetError() << std::endl;
            exit(1);
        }
        else
        {
            pTexture = SDL_CreateTextureFromSurface(pRenderer_copy, pSurface);
        }
    }
    else
    {
        pTexture = SDL_CreateTextureFromSurface(pRenderer, pSurface);
    }

    if (pTexture == nullptr)
    {
        std::cerr << "Failed to create texture " << SDL_GetError() << std::endl;
        exit(1);
    }

    SDL_FreeSurface(pSurface);

    return pTexture;
}

SDL_Renderer *GraphicsManager::getRenderer()
{
    if (pRenderer == nullptr)
    {
        // std::cerr << "pRenderer is null" << std::endl;
        if (pRenderer_copy == nullptr)
        {
            std::cerr << "pRenderer_copy is null" << std::endl;
            exit(1);
        }
        else
        {
            return pRenderer_copy;
        }
    }
    return pRenderer;
}

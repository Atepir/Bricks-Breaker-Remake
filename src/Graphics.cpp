#include "Graphics.hpp"

Graphics *Graphics::pInstance = nullptr;

Graphics *Graphics::getInstance()
{
    if (pInstance == nullptr)
    {
        pInstance = new Graphics();
    }
    return pInstance;
}

Graphics::Graphics()
{
    pWindow = nullptr;
    pRenderer = nullptr;
}

Graphics::~Graphics()
{
    quit();
}

void Graphics::init()
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
        std::cerr << "Failed to create renderer " << SDL_GetError() << std::endl;
        exit(1);
    }
}

void Graphics::update()
{
    SDL_RenderPresent(pRenderer);
}

void Graphics::clear()
{
    SDL_RenderClear(pRenderer);
}

void Graphics::draw()
{
    SDL_Rect rect = {0, 0, 1024, 720};
    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
    Paddle::getInstance()->draw();
}

void Graphics::quit()
{
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
}

SDL_Texture *Graphics::loadTexture(const char *pFilename)
{
    SDL_Surface *pSurface = SDL_LoadBMP(pFilename);
    if (pSurface == nullptr)
    {
        std::cerr << "Failed to load image " << pFilename << " " << SDL_GetError() << std::endl;
        exit(1);
    }

    SDL_Texture *pTexture = SDL_CreateTextureFromSurface(pRenderer, pSurface);
    if (pTexture == nullptr)
    {
        std::cerr << "Failed to create texture " << SDL_GetError() << std::endl;
        exit(1);
    }

    SDL_FreeSurface(pSurface);

    return pTexture;
}

SDL_Renderer *Graphics::getRenderer()
{
    return pRenderer;
}
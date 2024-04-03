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
    pSurface = nullptr;
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

    pSurface = SDL_GetWindowSurface(pWindow);
    if (pSurface == nullptr)
    {
        std::cerr << "Failed to get window surface " << SDL_GetError() << std::endl;
        exit(1);
    }

    pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
}

void Graphics::update()
{
    SDL_UpdateWindowSurface(pWindow);
}

void Graphics::clear()
{
    SDL_FillRect(pSurface, nullptr, SDL_MapRGB(pSurface->format, 0, 0, 0));
}

void Graphics::draw()
{
    SDL_Rect rect = {0, 0, 100, 100};
    SDL_FillRect(pSurface, &rect, SDL_MapRGB(pSurface->format, 255, 255, 255));
}

void Graphics::quit()
{
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
}

SDL_Renderer *Graphics::getRenderer()
{
    return pRenderer;
}
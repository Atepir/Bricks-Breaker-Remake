#include "core/App.hpp"

using namespace Core;
App *App::pInstance = nullptr;

App::App()
{
    currentScreen = nullptr;
    nextScreen = nullptr;
    init();
}

App::~App()
{
    quit();
}

App *App::getInstance()
{
    if (pInstance == nullptr)
    {
        pInstance = new App();
    }
    return pInstance;
}

void App::init()
{
    mRunning = true;

    Graphics::GraphicsManager *graphics = Graphics::GraphicsManager::getInstance();
    graphics->init();

    if (TTF_Init() == -1)
    {
        printf("Error - TTF_Init()\n");
        SDL_Delay(5000);
    }

    TTF_Font *smallFont = TTF_OpenFont("font.ttf", 64);
    if (smallFont == nullptr)
    {
        std::cerr << "Failed to load font.ttf" << std::endl;
        std::cerr << TTF_GetError() << std::endl;
    }
    std::cout << "smallFont: " << smallFont << std::endl;
    Font::setDefaultFonts(smallFont, smallFont);
}

void App::run()
{
    mainloop();
}

void App::quit()
{
    mRunning = false;
    Graphics::GraphicsManager::getInstance()->quit();
    TTF_Quit();
}

void App::setScreen(Gui::Screen *screen)
{
    nextScreen = screen;
}

Gui::Screen *App::getCurrentScreen()
{
    return currentScreen;
}

void App::mainloop()
{
    Graphics::GraphicsManager *graphics = Graphics::GraphicsManager::getInstance();

    while (mRunning)
    {
        Core::EventManager::getInstance()->handleEvents();

        if (nextScreen != nullptr)
        {
            if (currentScreen != nullptr)
            {
                delete currentScreen;
            }
            currentScreen = nextScreen;
            nextScreen = nullptr;
            currentScreen->init();
        }

        currentScreen->render(*graphics);
        graphics->render();
        SDL_Delay(1000);
    }
}
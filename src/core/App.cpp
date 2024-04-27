#include "core/App.hpp"

using namespace Core;
std::shared_ptr<App> App::pInstance = nullptr;

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

std::shared_ptr<App> App::getInstance()
{
    if (pInstance == nullptr)
    {
        pInstance = std::make_shared<App>();
    }
    return pInstance;
}

void App::init()
{
    mRunning = true;

    std::shared_ptr<Graphics::Renderer> graphics = Graphics::Renderer::getInstance();
    graphics->init();

    if (TTF_Init() == -1)
    {
        printf("Error - TTF_Init()\n");
        SDL_Delay(5000);
    }

    Type_TTF_Font font = TTF_OpenFont("font.ttf", 64);
    if (font == nullptr)
    {
        std::cerr << "Failed to load font.ttf" << std::endl;
        std::cerr << TTF_GetError() << std::endl;
    }
    std::cout << "font: " << font << std::endl;
    Font::setDefaultFont(font);
}

void App::run()
{
    mainloop();
}

void App::quit()
{
    mRunning = false;
    Graphics::Renderer::getInstance()->quit();
    TTF_Quit();
}

void App::setScreen(std::shared_ptr<Gui::Screen> screen)
{
    nextScreen = screen;
}

std::shared_ptr<Gui::Screen> App::getCurrentScreen()
{
    return currentScreen;
}

void App::mainloop()
{
    std::shared_ptr<Graphics::Renderer> graphics = Graphics::Renderer::getInstance();

    while (mRunning)
    {
        Core::EventManager::getInstance()->handleEvents();

        if (nextScreen != nullptr)
        {
            if (currentScreen != nullptr)
            {
                currentScreen = nullptr;
            }
            currentScreen = nextScreen;
            nextScreen = nullptr;
            currentScreen->init();
        }

        currentScreen->render(*graphics);
        graphics->render();
        SDL_Delay(10000);
    }
}
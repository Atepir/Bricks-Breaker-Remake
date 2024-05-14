#include "core/App.hpp"

using namespace Core;
std::shared_ptr<App> App::pInstance = nullptr;

App::App()
{
    mCurrentScreen = nullptr;
    mNextScreen = nullptr;
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
}

void App::run()
{
    mainloop();
}

void App::quit()
{
    mRunning = false;
    Graphics::Renderer::getInstance()->quit();
}

void App::setScreen(std::shared_ptr<Gui::Screen> screen)
{
    mNextScreen = screen;
}

std::shared_ptr<Gui::Screen> App::getCurrentScreen()
{
    return mCurrentScreen;
}

void App::mainloop()
{
    std::shared_ptr<Graphics::Renderer> graphics = Graphics::Renderer::getInstance();

    FPS fps = FPS(1000 / 24);

    while (mRunning)
    {
        fps.update();
        Core::EventManager::getInstance()->handleEvents();

        if (mNextScreen != nullptr)
        {
            if (mCurrentScreen != nullptr)
            {
                mCurrentScreen = nullptr;
            }
            mCurrentScreen = mNextScreen;
            mNextScreen = nullptr;

            // launch a separate thread for initialization as the game can be played there
            std::thread taskThread([this]()
                                   { mCurrentScreen->init(); });
            taskThread.join();
        }

        mCurrentScreen->render(*graphics);
        graphics->render();

        fps.delay();
    }
}
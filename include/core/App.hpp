#ifndef __APP_HPP
#define __APP_HPP

#include <SDL.h>
#include <SDL_ttf.h>

#include "graphics/Renderer.hpp"
#include "gui/Screen.hpp"
#include "resources/ResourceManager.hpp"

namespace Core
{
    class EventManager;

    class App
    {
    private:
        bool mRunning;
        static std::shared_ptr<App> pInstance;

        std::shared_ptr<Gui::Screen> currentScreen, nextScreen;

        void mainloop();
        void init();

    public:
        App();
        ~App();

        static std::shared_ptr<App> getInstance();

        void run();
        void quit();

        void setScreen(std::shared_ptr<Gui::Screen> screen);

        std::shared_ptr<Gui::Screen> getCurrentScreen();
    };
}

#include "core/EventManager.hpp"

#endif
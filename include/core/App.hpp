#ifndef __APP_HPP
#define __APP_HPP

#include <SDL.h>
#include <SDL_ttf.h>

#include "graphics/GraphicsManager.hpp"
#include "gui/Screen.hpp"
#include "resources/ResourceManager.hpp"

namespace Core
{
    class EventManager;

    class App
    {
    private:
        bool mRunning;
        static App *pInstance;

        Gui::Screen *currentScreen, *nextScreen;

        void mainloop();
        void init();

    public:
        App();
        ~App();

        static App *getInstance();

        void run();
        void quit();

        void setScreen(Gui::Screen *screen);

        Gui::Screen *getCurrentScreen();
    };
}

#include "core/EventManager.hpp"

#endif
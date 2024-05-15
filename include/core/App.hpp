#ifndef __APP_HPP
#define __APP_HPP

#include <iostream>
#include <thread>

#include "graphics/Renderer.hpp"
#include "gui/Screen.hpp"
#include "resources/ResourceManager.hpp"
#include "graphics/FPS.hpp"

namespace Core
{
    class EventManager;

    /**
     * @brief High level application singleton
     * @details Manages the rendered screen and holds the main loop
     */
    class App
    {
    private:
        bool mRunning;
        static std::shared_ptr<App> pInstance;

        std::shared_ptr<Gui::Screen> mCurrentScreen, mNextScreen;

        std::unique_ptr<Sound> mBackgroundMusic;

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

#include "graphics/EventManager.hpp"

#endif
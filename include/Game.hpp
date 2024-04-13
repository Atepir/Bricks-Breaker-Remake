#ifndef __GAME_HPP
#define __GAME_HPP

#include <SDL.h>

#include "graphics/Renderer.hpp"
#include "input/InputManager.hpp"

class Game
{
    private:
        bool mRunning;
        SDL_Window *mWindow;
        Renderer *mRenderer;

    public:
        Game();
        ~Game();

        void run();
        void update();
        void render();
        void handleEvents();
        void clean();
};
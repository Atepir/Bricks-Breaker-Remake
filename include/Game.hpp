#ifndef __GAME_HPP
#define __GAME_HPP

#include <SDL.h>

#include "graphics/Renderer.hpp"

class Game
{
    private:
        bool mRunning;
        SDL_Window *mWindow;
        Renderer *mRenderer;

        static Game *pInstance;

    public:
        Game();

        Game(const Game &) = delete;
        void operator=(const Game &) = delete;

        ~Game();

        static Game *getInstance();

        void run();
        
        void quit();

        void buttonPressed(SDL_Keycode pKey);
};

#endif
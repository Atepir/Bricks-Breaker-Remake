#ifndef __GAME_HPP
#define __GAME_HPP

#include <SDL.h>

#include "graphics/Renderer.hpp"
#include "gameobjects/GameObject.hpp"
#include "gameobjects/Ball.hpp"
#include "gameobjects/Paddle.hpp"
#include "gameobjects/Board.hpp"
#include "factories/BallFactory.hpp"
#include "resources/Enums.hpp"

namespace Core
{
    class Game
    {
    private:
        bool mRunning;

        static std::shared_ptr<Game> pInstance;

    public:
        Game();

        Game(const Game &) = delete;
        void operator=(const Game &) = delete;

        ~Game();

        static std::shared_ptr<Game> getInstance();

        void run();

        void quit();

        void buttonPressed(SDL_Keycode pKey);
    };
}

#endif
#ifndef __GAME_HPP
#define __GAME_HPP

#include <SDL.h>

#include "graphics/GraphicsManager.hpp"
#include "gameobjects/GameObject.hpp"
#include "resources/Enums.hpp"

class Game
{
private:
    bool mRunning;

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
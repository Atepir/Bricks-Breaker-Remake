#ifndef __INPUT_MANAGER_HPP
#define __INPUT_MANAGER_HPP

#include <SDL.h>
#include <vector>
#include <iterator>

class Game;

class InputManager
{
    public:
        InputManager();
        ~InputManager();

        void update();
};

#include "Game.hpp";

#endif
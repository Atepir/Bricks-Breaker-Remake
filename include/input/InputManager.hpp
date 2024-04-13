#ifndef __INPUT_MANAGER_HPP
#define __INPUT_MANAGER_HPP

#include <SDL.h>
#include <vector>
#include <iterator>
#include <algorithm>

class InputManager
{
    public:
        InputManager();
        ~InputManager();

        void update();
};

#endif
#include <SDL2/SDL.h>
#include <iostream>

SDL_Window *pWindow = nullptr;
SDL_Surface *win_surf = nullptr;

void init()
{
    pWindow = SDL_CreateWindow("BricksBreaker Remake!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 720, SDL_WINDOW_SHOWN);
    win_surf = SDL_GetWindowSurface(pWindow);
}

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Echec de l'initialisation de la SDL " << SDL_GetError() << std::endl;
        return 1;
    }

    init();

    // Main loop
    bool quit = false;
    while (!quit)
    {
        SDL_Event event;
        while (!quit && SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            default:
                break;
            }
        }

        // Keyboard input management
        int nbk;
        const Uint8 *keys = SDL_GetKeyboardState(&nbk);
        if (keys[SDL_SCANCODE_ESCAPE])
            quit = true;

        SDL_UpdateWindowSurface(pWindow);
        // Limit frame rate to 60 fps
        SDL_Delay(16); // utiliser SDL_GetTicks64() pour plus de precisions
    }

    SDL_Quit(); // Quit SDL

    return 0;
}

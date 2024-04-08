#include "Main.hpp"

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Echec de l'initialisation de la SDL " << SDL_GetError() << std::endl;
        return 1;
    }

    Graphics graphics = Graphics();
    graphics.init();

    Paddle *paddle = Paddle::getInstance();

    eMapType mapType = eMapType::Circular;

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

        graphics.draw();
        graphics.update(mapType);

        // Limit frame rate to 60 fps
        SDL_Delay(16); // utiliser SDL_GetTicks64() pour plus de precisions
    }

    SDL_Quit(); // Quit SDL

    return 0;
}

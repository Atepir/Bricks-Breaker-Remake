#ifndef FPS_H
#define FPS_H

#include <SDL.h>
#include <iostream>

class FPS
{
private:
    float intervalMs;
    int frames;
    int lastTime;
    int current;

public:
    FPS(float intervalMs) : frames(0), current(0), intervalMs(intervalMs)
    {
        lastTime = SDL_GetTicks();
    }

    void update()
    {
        frames++;
        if (lastTime < SDL_GetTicks() - intervalMs)
        {
            lastTime = SDL_GetTicks();
            current = frames;
            frames = 0;
        }
    }

    int getFPS()
    {
        return current;
    }

    void delay()
    {
        int frameTicks = SDL_GetTicks() - lastTime;
        if (frameTicks < intervalMs)
        {
            SDL_Delay(intervalMs - frameTicks);
        }
    }
};

#endif
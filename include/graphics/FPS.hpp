#ifndef FPS_H
#define FPS_H

#include <SDL.h>
#include <iostream>

namespace Graphics
{
    /**
     * @brief Holds the frames per second
     */
    class FPS
    {
    private:
        float mIntervalMs;
        int mFrames;
        int mLastTime;
        int mCurrent;

    public:
        FPS(float intervalMs) : mFrames(0), mCurrent(0), mIntervalMs(intervalMs)
        {
            mLastTime = SDL_GetTicks();
        }

        void update()
        {
            mFrames++;
            if (mLastTime < SDL_GetTicks() - mIntervalMs)
            {
                mLastTime = SDL_GetTicks();
                mCurrent = mFrames;
                mFrames = 0;
            }
        }

        void delay()
        {
            int frameTicks = SDL_GetTicks() - mLastTime;
            if (frameTicks < mIntervalMs)
            {
                SDL_Delay(mIntervalMs - frameTicks);
            }
        }
    };
}

#endif
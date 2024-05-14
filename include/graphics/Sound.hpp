#ifndef __SOUND_HPP
#define __SOUND_HPP

#include <SDL_mixer.h>

#include <string>
#include <memory>

namespace Graphics
{
    using Type_Mix_Music = Mix_Music *;

    class Sound
    {
    private:
        Type_Mix_Music mMusic;
        std::string mPath;

    public:
        Sound(std::string pPath) : mPath(pPath)
        {
            mMusic = Mix_LoadMUS(pPath.c_str());
            if (mMusic == nullptr)
            {
                std::cerr << "Failed to load music: " << pPath << " - " << Mix_GetError() << std::endl;
            }
            else if (mMusic == NULL)
            {
                std::cerr << "Failed to load music: " << pPath << " - " << Mix_GetError() << std::endl;
            }
            else
            {
                std::cout << "Music loaded successfully" << std::endl;
            }
        }

        ~Sound()
        {
            Mix_FreeMusic(mMusic);
        }

        void play(bool pLoop = false)
        {
            Mix_PlayMusic(mMusic, pLoop ? -1 : 0);
        }

        void stop()
        {
            Mix_HaltMusic();
        }
    };
}

#endif
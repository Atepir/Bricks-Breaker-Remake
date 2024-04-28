#ifndef __LEVEL_MANAGER_HPP__
#define __LEVEL_MANAGER_HPP__

#include <iostream>
#include <vector>

namespace Resources
{

    class LevelManager
    {
    private:
        static inline int mCurrentLevel = 0;
        static inline std::vector<std::string> mLevelPaths = {
            "boards/level0.txt",
            "boards/level1.txt",
            "boards/level2.txt",
            "boards/level3.txt",
            "boards/level4.txt",
        };

    public:
        static inline std::string
        getCurrentLevelPath() { return mLevelPaths[mCurrentLevel]; }
        static inline void setLevel(int pLevel) { mCurrentLevel = pLevel; }
        static inline int getCurrentLevel() { return mCurrentLevel; }
    };
}

#endif
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

        static inline int mCurrentCircularLevel = 0;
        static inline std::vector<std::string> mCircularLevelPaths = {
            "circular_boards/level0.txt",
            "circular_boards/level1.txt",
            "circular_boards/level2.txt",
            "circular_boards/level3.txt",
            "circular_boards/level4.txt",
        };

    public:
        static inline std::string
        getCurrentLevelPath() { return mLevelPaths[mCurrentLevel]; }
        static inline void setLevel(int pLevel) { mCurrentLevel = pLevel; }
        static inline int getCurrentLevel() { return mCurrentLevel; }

        static inline std::string
        getCurrentCircularLevelPath() { return mCircularLevelPaths[mCurrentCircularLevel]; }
        static inline void setCircularLevel(int pLevel) { mCurrentCircularLevel = pLevel; }
        static inline int getCurrentCircularLevel() { return mCurrentCircularLevel; }
    };
}

#endif
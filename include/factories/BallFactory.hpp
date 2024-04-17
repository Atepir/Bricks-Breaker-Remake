#ifndef __BALL_FACTORY_HPP
#define __BALL_FACTORY_HPP

#include "gameobjects/Ball.hpp"
#include "geometry/Dimensions.hpp"

class BallFactory
{
public:
    BallFactory() = default;
    virtual ~BallFactory() = default;

    static Ball *createBall(BallType pType);
};

#endif // __BALL_FACTORY_HPP

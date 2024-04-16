#ifndef __ENUM_H
#define __ENUM_H

enum eMapType
{
	Basic,
	Circular
};

enum class BrickType
{
	NORMAL,
	UNBREAKABLE
};

enum class BallType
{
	NORMAL,
	EXPLOSIVE
};

enum Direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

enum PaddleType
{
	BasicPaddle,
	CircularPaddle,
};

enum GameObjectType
{
	GameObjectBall,
	GameObjectPaddle,
	GameObjectBrick
};

#endif
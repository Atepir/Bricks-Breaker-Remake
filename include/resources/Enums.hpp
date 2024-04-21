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

enum class Direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

enum class PaddleType
{
	BasicPaddle,
	CircularPaddle,
};

enum class GameObjectType
{
	GameObjectBall,
	GameObjectPaddle,
	GameObjectBrick
};

enum class eTextureKey
{
	Texture_Paddle_Basic,
	Texture_Paddle_Circular,
	Texture_Ball_Basic,
	Texture_Ball_Circular,
	Texture_Brick_Normal,
	Texture_Brick_Unbreakable
};

#endif
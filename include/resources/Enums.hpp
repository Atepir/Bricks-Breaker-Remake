#ifndef __ENUMS_HPP
#define __ENUMS_HPP

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
	Texture_Brick_Unbreakable,
	Texture_Main_Menu_Background,
	Texture_Heart,
	Texture_Brick_Normal_Damaged
};

enum eColor
{
	ColorWhite = 0,
	ColorBlack = 1,
	ColorRed = 2,
	ColorGreen = 3,
	ColorBlue = 4,
	ColorYellow = 5,
	ColorCyan = 6,
	ColorMagenta = 7
};

#endif
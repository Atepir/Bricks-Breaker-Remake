#ifndef __ENUMS_HPP
#define __ENUMS_HPP

enum eMapType
{
	Basic,
	Circular
};

enum class BrickType
{
	BRICK_BLUE,
	BRICK_GREEN,
	BRICK_VIOLET,
	BRICK_YELLOW,
	BRICK_RED
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
	GameObjectBrick,
	GameObjectPower,
};

enum class eTextureKey
{
	Texture_Paddle_Basic,
	Texture_Paddle_Basic_Large,
	Texture_Paddle_Basic_Small,
	Texture_Paddle_Circular,
	Texture_Ball_Basic,
	Texture_Ball_Circular,
	Texture_Brick_Normal,
	Texture_Brick_Green,
	Texture_Brick_Violet,
	Texture_Brick_Yellow,
	Texture_Brick_Red,
	Texture_Main_Menu_Background,
	Texture_Heart,
	Texture_Brick_Normal_Damaged,
	Texture_Brick_Green_Damaged,
	Texture_Brick_Violet_Damaged,
	Texture_Brick_Yellow_Damaged,
	Texture_Brick_Red_Damaged,
	Texture_Board_Border_Background,
	Texture_Circular_Board_Background,
	Texture_Powerup_Expand_Ball,
	Texture_Powerdown_Shrink_Ball,
	Texture_Powerup_Expand_Paddle,
	Texture_Powerdown_Shrink_Paddle,
	Texture_Powerup_Extra_Life,
	Texture_Powerup_Multi_Ball,
};

enum PowerType
{
	POWERUP_EXPAND_BALL,
	POWERDOWN_SHRINK_BALL,
	POWERUP_EXPAND_PADDLE,
	POWERDOWN_SHRINK_PADDLE,
	POWERUP_EXTRA_LIFE,
	POWERUP_MULTI_BALL
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
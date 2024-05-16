#ifndef __ENUMS_HPP
#define __ENUMS_HPP

enum eMapType
{
	Map_Basic,
	Map_Circular
};

enum class eBrickType
{
	Brick_Blue,
	Brick_Green,
	Brick_Violet,
	Brick_Yellow,
	Brick_Red
};

enum class eBallType
{
	Ball_Normal,
	Ball_Explosive
};

enum class ePaddleType
{
	Paddle_Basic,
	Paddle_Circular,
};

enum class eGameObjectType
{
	GameObject_Ball,
	GameObject_Paddle,
	GameObject_Brick,
	GameObject_Power,
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

enum ePowerType
{
	PowerUp_Expand_Ball,
	PowerDown_Shrink_Ball,
	PowerUp_Expand_Paddle,
	PowerDown_Shrink_Paddle,
	PowerUp_Extra_Life,
	PowerUp_Multi_Ball
};

enum eColor
{
	Color_White = 0,
	Color_Black = 1,
	Color_Red = 2,
	Color_Green = 3,
	Color_Blue = 4,
	Color_Yellow = 5,
	Color_Cyan = 6,
	Color_Magenta = 7
};

#endif
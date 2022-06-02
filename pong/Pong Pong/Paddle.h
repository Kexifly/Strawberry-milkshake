#pragma once
#include "raylib.h"

// A Struct for both left and right paddle to access. 
struct Paddle
{
	float x, y;
	float speed;
	float width, height;
	
	Rectangle GetRec()
	{
		return Rectangle{ x - width / 2, y - height / 2 , width, height };
	}
	// Draw the paddle and determine the color. 
	void Draw()
	{
		DrawRectangleRec(GetRec(), DARKBLUE);
	}
};
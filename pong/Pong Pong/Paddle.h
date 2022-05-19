#pragma once
#include "raylib.h"

struct Paddle
{
	float x, y;
	float speed;
	float width, height;
	Rectangle GetRec()
	{
		return Rectangle{ x - width / 2, y - height / 2 , width, height };
	}
	void Draw()
	{
		DrawRectangleRec(GetRec(), DARKBLUE);
	}
};
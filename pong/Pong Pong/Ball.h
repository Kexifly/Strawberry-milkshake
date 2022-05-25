#pragma once
#include "raylib.h"

 struct Ball
{
	float x, y;
	float speedX, speedY;
	float radius;

	void Draw()
	{
		DrawCircle((int)x, (int)y, radius, GREEN);
	}

};

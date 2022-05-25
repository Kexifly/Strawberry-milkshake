#include "Ball.h"

 void Ball::Draw()
{
	DrawTexture(ball, (int)x, (int)y, WHITE);
}

Ball::Ball()
{
	x = -GetScreenWidth() / 2.0f;
	y = GetScreenHeight() / 2.0f;
	radius = 5;
	speedX = 100;
	speedY = 300;
}

void Ball::Update()
{
	x += speedX * GetFrameTime();
	y += speedY * GetFrameTime();

	if (y < 0)
	{
		y = 0;
		speedY *= -1;
	}
	if (y > GetScreenHeight())
	{
		y = GetScreenHeight();
		speedY *= -1;
	}
}

void Ball::Reset()
{
	x = GetScreenWidth() / 2;
	y = GetScreenHeight() / 2;
	speedX = 100;
	speedY = 300;
}

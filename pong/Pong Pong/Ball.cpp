#include "Ball.h"

 void Ball::Draw()
{
	DrawTexture(ball, (int)x, (int)y, WHITE);
}

Ball::Ball()
{
	x = -GetScreenWidth() / 2.0f;
	y = GetScreenHeight() / 2.0f;
	radius = ball.width * 0.5f;
	speedX = 100;
	speedY = 300;
}

Vector2 Ball::GetPosition() const
{
	return Vector2{ x + ball.width * 0.5f, y + ball.height * 0.5f };
}
float Ball::GetRadius() const
{
	return radius;
}
Vector2 Ball::GetVelocity() const
{
	return Vector2 {speedX, speedY};
}
void Ball::ReflectVelocity(float scale)
{
	speedX *= -scale;
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

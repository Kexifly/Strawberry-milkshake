#include "Ball.h"

// Accessing our ball class and our Draw function from our header file. 
 void Ball::Draw()
{
	 // Draw the ball texture to the screen. 
	DrawTexture(ball, (int)x, (int)y, WHITE);
}
// Creating a function for our ball whilst accessing the ball class.  
Ball::Ball()
{
	// Setting values for the x and y. 
	x = -GetScreenWidth() / 2.0f;
	y = GetScreenHeight() / 2.0f;
	// Setting values for the radius.
	radius = ball.width * 0.5f;
	// Setting the values for the speedX and speedY. 
	speedX = 100;
	speedY = 300;
}
// This is our GetPosition function which is for.. you guessed it! 
Vector2 Ball::GetPosition() const
{
	//Normalize the asset so it is better implemented in the collison check in main.
	return Vector2{ x + ball.width * 0.5f, y + ball.height * 0.5f };
}
// This is our Get Radius function so we can access the values in main for collison checks. 
float Ball::GetRadius() const
{
	return radius;
}
// This is our GetVelocity function so we can access the values in main for collison checks. 
Vector2 Ball::GetVelocity() const
{
	return Vector2 {speedX, speedY};
}
// This is our ReflectVelocity function that 
void Ball::ReflectVelocity(float scale)
{
	speedX *= -scale;
}
// This is our Update function which controls the movement of the ball on screen. 
void Ball::Update()
{

	x += speedX * GetFrameTime();
	y += speedY * GetFrameTime();
	// This is the logic that stops the ball from going off the screen. 
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
// This is our Reset function that holds the ball starting point values/variables. 
void Ball::Reset()
{
	x = GetScreenWidth() / 2;
	y = GetScreenHeight() / 2;
	speedX = 100;
	speedY = 300;
}

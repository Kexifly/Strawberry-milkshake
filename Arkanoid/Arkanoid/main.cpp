#include <iostream>
#include "sound.h"
#include "raylib.h"
#include "ball.h"
#include "vaus.h"
#include "brick.h"

// Define the screen Width and Height. 
#define SCREEN_WIDTH 1440
#define SCREEN_HEIGHT 900

int main()
{
	// Call the PlaySoundTrack Function (Makes the sound happen).
	PlaySoundTrack();
	// Creates console window and allows you to name the application. 
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Arkanoid");
	// This is where we specify the target frame rate.
	SetTargetFPS(120);
	// Here is where I load in the background texture. 
	Texture2D background = LoadTexture("..\\..\\Images\\space.png");
	// Creating the ball object.
	Ball ball; 
	// Creating the vaus object.
	Vaus paddle;
	// Creating the brick object.
	Brick brick;
	
	// Starting with while the window is NOT closed - run code. 
	while (!WindowShouldClose())
	{

		// If pressing the LEFT key the vaus will move sidways to the left.
		if (IsKeyDown(KEY_LEFT))
		{
			paddle.x -= paddle.speed * GetFrameTime();
		}
		// If pressing the RIGHT key the vaus will go sideways to the right.
		if (IsKeyDown(KEY_RIGHT))
		{
			paddle.x += paddle.speed * GetFrameTime();
		}
		ball.Update();

		// Collison check with ball and vaus. 
		if (CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), paddle.GetRec()))
		{
			// if statement that determines how the ball gains velocity upon hitting the vaus.
			if (ball.GetVelocity().x < 0)
			{
				ball.ReflectVelocity(1.1f);

			}
		}
		//Screen Collision With Vaus.
		// 
		// Right
		if (paddle.x + paddle.vaus.width> SCREEN_WIDTH)
		{
			paddle.x = SCREEN_WIDTH - paddle.vaus.width -1;
		}
		// Left
		if (paddle.x < 0)
		{
			paddle.x = 1;
		}

		BeginDrawing();
		DrawTexture(background, 0, 0, WHITE);
		DrawFPS(15, 15);
		ball.Draw();
		paddle.Draw();
		EndDrawing();

	}
	bool WindowShouldClose();


	return 0;

}
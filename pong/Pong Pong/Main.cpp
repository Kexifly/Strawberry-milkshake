#include <iostream>
#include "raylib.h"
#include "Ball.h"
#include "Paddle.h"
#include "Sound.h"


// Define the screen Width and Height. 
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


int main()
{

	// Call the PlaySoundTrack Function (Makes the sound happen).
	PlaySoundTrack();
	// Creates console window and allows you to name the application. 
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong Pong");
	// Implements Full-Screen Mode
	ToggleFullscreen();
	// This is where we specify the target frame rate.
	SetTargetFPS(120);
	// Creating the ball object.
	//----------------------------------------------------------------------------------------------------------------------

	Ball ball;
	// Creating the LEFT paddle object.
	Paddle leftPaddle;
	leftPaddle.x = 50;
	leftPaddle.y = GetScreenHeight() / 2;
    leftPaddle.width = 10;
	leftPaddle.height = 100;
	leftPaddle.speed = 500;
	// Creating the RIGHT paddle object.
	Paddle rightPaddle;
	rightPaddle.x = GetScreenWidth() - 50;
	rightPaddle.y = GetScreenHeight() / 2;
	rightPaddle.width = 10;
	rightPaddle.height = 100;
	rightPaddle.speed = 500;
	// This is where we create the winner condition variables. 
	const char* winnerPointOne = nullptr;
	const char* winnerPointTwo = nullptr;
	const char* winnerText = nullptr;
	// Here is where I load in the background texture. 
	Texture2D background = LoadTexture("..\\..\\Images\\vortex.png");
	// This is where we create the Player Point variables for both P1 and P2.
	int Player1Points = 0;
	int Player2Points = 0;
	// This is the start of our while loop that holds majority of our logic.
	// Starting with while the window is NOT closed - run code. 
	//-----------------------------------------------------------------------------------------------------------------------

		while (!WindowShouldClose())
		{
			
			// If pressing W the left paddle will go up towards the top of the screen.
			if (IsKeyDown(KEY_W))
			{
				leftPaddle.y -= leftPaddle.speed * GetFrameTime();
			}
			// If pressing S the left paddle will go down towards the bottom of the screen.
			if (IsKeyDown(KEY_S))
			{
				leftPaddle.y += leftPaddle.speed * GetFrameTime();
			}
			// If pressing the UP key the right paddle will go up towards the top of the screen.
			if (IsKeyDown(KEY_UP))
			{
				rightPaddle.y -= rightPaddle.speed * GetFrameTime();
			}
			// If pressing the DOWN key the right paddle will go down towards the bottom of the screen.
			if (IsKeyDown(KEY_DOWN))
			{
				rightPaddle.y += rightPaddle.speed * GetFrameTime();
			}
			//---------------------------------------------------------------------------------------------------------------
			
			// Here we call the Update fuction on our ball to get it moving. 
			ball.Update();

			//---------------------------------------------------------------------------------------------------------------
			
			// Collison check with the ball and the left paddle. 
			if (CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), leftPaddle.GetRec()))
			{
				// if statement that determines how the ball gains velocity upon hitting the paddle.
				if (ball.GetVelocity().x < 0)
				{
					ball.ReflectVelocity(1.1f);
					
				}
			}
			// Collison check with the ball and the right paddle. 
			if (CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), rightPaddle.GetRec()))
			{
				// if statement that determines how the ball gains velocity upon hitting the paddle.
				if (ball.GetVelocity().x > 0)
				{
					ball.ReflectVelocity(1.1f);
					
				}
			} 
			//Screen Collision With Paddles.
			//Top Left
			if (leftPaddle.y < leftPaddle.height / 2.f)
			{
				leftPaddle.y = leftPaddle.height / 2.f;
			}
			//Bottom Left 
			if (leftPaddle.y + leftPaddle.height / 2 > SCREEN_HEIGHT)
			{
				leftPaddle.y = SCREEN_HEIGHT - leftPaddle.height / 2;
			}
			// Top Right
			if (rightPaddle.y < rightPaddle.height / 2.f)
			{
				rightPaddle.y = rightPaddle.height / 2.f;
			}
			//Bottom Right
			if (rightPaddle.y + rightPaddle.height / 2 > SCREEN_HEIGHT)
			{
				rightPaddle.y = SCREEN_HEIGHT - rightPaddle.height / 2;
			}
			//---------------------------------------------------------------------------------------------------------------
			// Points
			// This is where we set a condition for P2 to get points if the ball goes of the left side of the screen.
			if (ball.GetPosition().x < 0)
			{
				Player2Points += 1;
				// Ball respawns on the screen. 
				ball.Reset();
			}
			// This is where we set a condition for P1 to get points if the ball goes of the right side of the screen.
			if (ball.GetPosition().x > GetScreenWidth())
			{
				Player1Points += 1;
				// Ball respawns on the screen.
				ball.Reset();
			}
			// This is where we set the conditions for winning the game. 
			// If P1 reaches 5 points we get a winner text to the screen.
			if (Player1Points == 5)
			{
				// winner text to the screen.
				winnerText = ("Left Player Wins!");
			}
			// If P2 reaches 5 points we get a winner text to the screen.
			if (Player2Points == 5)
			{
				// winner text to the screen.
				winnerText = ("Right Player Wins");
			}
			// If we have a winner and the SPACE key is pressed we reset the entire game and all the points. 
			if (winnerText && IsKeyPressed(KEY_SPACE))
			{
				Player1Points = 0;
				Player2Points = 0;
				// Ball respawns on screen.
				ball.Reset();
				winnerText = nullptr;
			}
			// This if statement Draws the winner text to the screen. 
			if (winnerText)
			{
				int textWidth = MeasureText(winnerText, 60);
				DrawText(winnerText, GetScreenWidth() / 2 - textWidth / 2, GetScreenHeight() / 2 - 30, 60, GREEN);
			}
			//---------------------------------------------------------------------------------------------------------------
			// Draw

			BeginDrawing();
			// Draw our custom asset background to the screen.
			DrawTexture(background, 0,0, WHITE);
			// Draw our ball to the screen.
			ball.Draw();
			// Draw our left paddle to the screen.
			leftPaddle.Draw();
			// Draw our right paddle to the screen. 
			rightPaddle.Draw();
			// Draw the FPS (Frame Rate Speed) to screen. (Left hand corner).
			DrawFPS(10, 10);
			// Finish Drawing.
			EndDrawing();
		}
		// Closing the window
		bool WindowShouldClose();
	
		return 0;
}

 
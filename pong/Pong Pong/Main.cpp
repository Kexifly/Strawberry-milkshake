#include <iostream>
#include "raylib.h"
#include "Ball.h"
#include "Paddle.h"
#include "Sound.h"



#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


int main()
{

	//SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	PlaySoundTrack();
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong Pong");
	ToggleFullscreen();
	SetTargetFPS(120);
	Ball ball;
	

	Paddle leftPaddle;
	leftPaddle.x = 50;
	leftPaddle.y = GetScreenHeight() / 2;
    leftPaddle.width = 10;
	leftPaddle.height = 100;
	leftPaddle.speed = 500;

	Paddle rightPaddle;
	rightPaddle.x = GetScreenWidth() - 50;
	rightPaddle.y = GetScreenHeight() / 2;
	rightPaddle.width = 10;
	rightPaddle.height = 100;
	rightPaddle.speed = 500;

	const char* winnerPointOne = nullptr;
	const char* winnerPointTwo = nullptr;
	const char* winnerText = nullptr;

	Texture2D background = LoadTexture("..\\..\\Images\\vortex.png");
	
	int Player1Points = 0;
	int Player2Points = 0;

		while (!WindowShouldClose())
		{
			
			
			if (IsKeyDown(KEY_W))
			{
				leftPaddle.y -= leftPaddle.speed * GetFrameTime();
			}
			if (IsKeyDown(KEY_S))
			{
				leftPaddle.y += leftPaddle.speed * GetFrameTime();
			}
			if (IsKeyDown(KEY_UP))
			{
				rightPaddle.y -= rightPaddle.speed * GetFrameTime();
			}
			if (IsKeyDown(KEY_DOWN))
			{
				rightPaddle.y += rightPaddle.speed * GetFrameTime();
			}

			ball.Update();

			if (CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), leftPaddle.GetRec()))
			{
				if (ball.GetVelocity().x < 0)
				{
					ball.ReflectVelocity(1.1f);
					
				}
			}
			 
			if (CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), rightPaddle.GetRec()))
			{
				if (ball.GetVelocity().x > 0)
				{
					ball.ReflectVelocity(1.1f);
					
				}
			} 
			//Screen Collision With Paddles
			//Top Left
			if (leftPaddle.y < leftPaddle.height / 2.f)
			{
				leftPaddle.y = leftPaddle.height / 2.f;
			}

			//Bottom Left 
			if (leftPaddle.y + leftPaddle.height / 2 > SCREEN_HEIGHT)
			{
				//	Paddle.setPosition(Paddle.getPosition().x, SCREEN_HEIGHT - Paddle.getGlobalBounds().height);
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

			// Points
			if (ball.GetPosition().x < 0)
			{
				Player2Points += 1;
				ball.Reset();
			}

			if (ball.GetPosition().x > GetScreenWidth())
			{
				Player1Points += 1;
				ball.Reset();
			}

			if (Player1Points == 5)
			{
				winnerText = ("Left Player Wins!");
			}
			if (Player2Points == 5)
			{
				winnerText = ("Right Player Wins");
			}

			if (winnerText && IsKeyPressed(KEY_SPACE))
			{
				Player1Points = 0;
				Player2Points = 0;
				ball.Reset();
				winnerText = nullptr;
			}


			BeginDrawing();
			
			////Image background = 	(LoadImage("\\..vortex.png"));
			

			
			ClearBackground(BLACK);
			DrawTexture(background, 0,0, WHITE);
			ball.Draw();
			leftPaddle.Draw();
			rightPaddle.Draw();

			if (winnerText)
			{
				int textWidth = MeasureText(winnerText, 60);
				DrawText(winnerText, GetScreenWidth() / 2 - textWidth / 2, GetScreenHeight() / 2 - 30, 60, GREEN);
			}
			
			DrawFPS(10, 10);
			EndDrawing();
		}
		bool WindowShouldClose();
	
	return 0;
}

 
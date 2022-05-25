#include <iostream>
#include "raylib.h"
#include "Ball.h"
#include "Paddle.h"
#include "Collision.h"
#include "Sound.h"


#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main()
{

	//SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong Pong");
	ToggleFullscreen();
	SetTargetFPS(120);
	Ball ball;
	ball.x = - GetScreenWidth() / 2.0f;
	ball.y = GetScreenHeight() / 2.0f;
	ball.radius = 5;
	ball.speedX = 100;
	ball.speedY = 300;

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

	const char* winnerText = nullptr;
	Texture2D background = LoadTexture("..\\..\\Images\\vortex.png");
		while (!WindowShouldClose())
		{
			
			ball.x += ball.speedX * GetFrameTime();
			ball.y += ball.speedY * GetFrameTime();

			if (ball.y < 0)
			{
				ball.y = 0;
				ball.speedY *= -1;
			}
			if (ball.y > GetScreenHeight())
			{ 
				ball.y = GetScreenHeight();
				ball.speedY *= -1;
			}
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

			if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius,leftPaddle.GetRec()))
			{
				if (ball.speedX < 0)	
				{
					ball.speedX *= -1.1f;
					//ball.speedY = (ball.y - leftPaddle.y) * ball.speedX / (leftPaddle.height / 2);
				}
			}
			// 
			if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, rightPaddle.GetRec()))
			{
				if (ball.speedX > 0)
				{
					ball.speedX *= -1.1f;
					//ball.speedY = (ball.y - rightPaddle.y * ball.speedX / (rightPaddle.height / 2)) ;
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

			if (ball.x < 0)
			{
				winnerText = " Right Player! You Win!";
			}

			if (ball.x > GetScreenWidth())
			{
				winnerText = " Left Player! You Win!";
			}

			if (winnerText && IsKeyPressed(KEY_SPACE))
			{
				ball.x = GetScreenWidth() / 2;
				ball.y = GetScreenHeight() / 2;
				ball.speedX = 100;
				ball.speedY = 300;
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

 
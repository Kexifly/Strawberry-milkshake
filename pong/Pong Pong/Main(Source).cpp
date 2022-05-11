#include <iostream>
#include "raylib.h"



int main()
{
	InitWindow(800, 600, "Pong Pong");
	//SetWindowState(FLAG_VSYNC_HINT);
	
	float ballX = GetScreenWidth() / 2;
	float ballY = GetScreenHeight() / 2;
	float ballRadius = 5;

	float paddLX;
	float paddLY;
	float paddLRadius;

	float paddRX = GetScreenWidth() - 50 - 10;
	float paddRY = GetScreenHeight() / 2 - 50;
	float paddRRadius = 100;

		while (!WindowShouldClose())
		{
			BeginDrawing();
			ClearBackground(BLACK);

			DrawCircle(ballX, ballY, ballRadius, DARKBLUE);
			DrawRectangle(50, GetScreenHeight() / 2 - 50, 10, 100, DARKBLUE);
			DrawRectangle(GetScreenWidth() - 50 - 10, GetScreenHeight() / 2 - 50, 10, 100, DARKBLUE);
			DrawFPS(10, 10);
			EndDrawing();
		}
	CloseWindow();
	return 0;
}


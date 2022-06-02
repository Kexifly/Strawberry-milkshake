#include <iostream>
#include "sound.h"
#include "raylib.h"
#include "ball.h"
#include "vaus.h"
#include "brick.h"

#define SCREEN_WIDTH 450
#define SCREEN_HEIGHT 437

int main()
{
	PlaySoundTrack();
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Arkanoid");
	SetTargetFPS(120);
	Texture2D background = LoadTexture("..\\..\\Images\\");
	
	Ball ball; 

	Vaus vaus;

	Brick brick;





















}
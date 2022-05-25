#pragma once
#include "raylib.h"


 class Ball
{
    Texture2D ball = LoadTexture("..\\..\\Images\\yellowball.png");
	float x, y;
	float speedX, speedY;
	float radius;
  public:
	  void Draw();

	Ball();

	void Update();

	void Reset();
};
 

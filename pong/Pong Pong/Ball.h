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

	Vector2 GetPosition() const;

	float GetRadius() const;

	Vector2 GetVelocity() const;

	void ReflectVelocity(float scale);

	void Update();

	void Reset();
};
 

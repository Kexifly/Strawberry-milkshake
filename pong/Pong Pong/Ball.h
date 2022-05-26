#pragma once
#include "raylib.h"

// A class for our Ball. 
 class Ball
{
	// Here we load in the custom tecture for our ball. 
    Texture2D ball = LoadTexture("..\\..\\Images\\yellowball.png");
	float x, y;
	float speedX, speedY;
	float radius;
	// Everything below will be public (access)
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
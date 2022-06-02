#pragma once
#include "raylib.h"

class Ball
{
	// Here we load in the custom tecture for our ball. // ADD SPRITE
	Texture2D ball = LoadTexture("..\\..\\Images\\?????.png");
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
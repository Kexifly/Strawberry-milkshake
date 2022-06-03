#pragma once
#include "raylib.h"

struct Vaus
{
	// Here we load in the custom tecture for our vaus. //CHECK IF IMAGE WORKS

	Texture2D vaus = LoadTexture("..\\..\\Images\\smallvaus.png");
	float x, y;
	float speed;
	float radius;
	

	// Everything below will be public (access)

	void Draw();

	Vaus();

	Rectangle GetRec();

	float GetRadius() const;

	/*Vector2 GetVelocity() const;

	void ReflectVelocity(float scale);*/

	//void Update();*/
};
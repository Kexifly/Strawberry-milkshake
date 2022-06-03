#include "vaus.h"
#include "raylib.h"

void Vaus::Draw()
{
	DrawTexture(vaus, (int)x, (int)y, WHITE);
}

Vaus::Vaus()
{
	// Setting values for the x and y. 
	x = GetScreenWidth() / 2;
	y = GetScreenHeight() - 90;
	// Setting values for the radius.
	radius = vaus.width;
	// Setting the value for the speed.
	speed = 1000;
}

Rectangle Vaus::GetRec() 
{
	return Rectangle{ x + vaus.width, y + vaus.height};
}

float Vaus::GetRadius() const
{
	return radius;
}

//void Vaus::ReflectVelocity(float scale)
//{
//	speed *= -scale;
//}

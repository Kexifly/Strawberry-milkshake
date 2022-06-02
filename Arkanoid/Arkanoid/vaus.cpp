#include "vaus.h"
#include "raylib.h"

void Vaus::Draw()
{
	DrawTexture(vaus, (int)x, (int)y, WHITE);
}

Vaus::Vaus()
{
	// Setting values for the x and y. 
	x = -GetScreenWidth() / 2.0f;
    y = GetScreenHeight() / 2.0f;
	// Setting values for the radius.
	radius = vaus.width * 0.5f;
	// Setting the value for the speed.
	speed = 500;
};

Rectangle Vaus::GetPositionVaus() 
{
	return Rectangle{ x + vaus.width * 0.5f, y + vaus.height * 0.5f };
}

float Vaus::GetRadius() const
{
	return radius;
}

//void Vaus::ReflectVelocity(float scale)
//{
//	speed *= -scale;
//}

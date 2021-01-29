#include "Car.h"
#include "Colors.h"

bool Car::Obstruct() 
{
	return true;
}

void Car::Draw(HDC hdc, Palette& palette)
{
	int width = length / 2;
	SelectObject(hdc, palette.BlackPen);
	SelectObject(hdc, palette.GetBrush(color));

	if (IsHorizontal()) 
	{
		Point topLeft(pos.x - length / 2, pos.y - width / 2);
		Point botRight(pos.x + length / 2, pos.y + width / 2);
		Rectangle(hdc, topLeft.x, topLeft.y, botRight.x, botRight.y);
	} else 
	{
		Point topLeft(pos.x - width / 2, pos.y - length / 2);
		Point botRight(pos.x + width / 2, pos.y + length / 2);
		Rectangle(hdc, topLeft.x, topLeft.y, botRight.x, botRight.y);
	}
}

bool Car::IsHorizontal()
{
	return direction.x != 0;
}

void Car::Update(int frameTime)
{
	MakeDecision();
	UpdatePosition(frameTime);
}

void Car::MakeDecision()
{

}

void Car::UpdatePosition(int frameTime)
{
	pos = pos + direction * (speed * 10.0) * (frameTime / 1000.0);
}
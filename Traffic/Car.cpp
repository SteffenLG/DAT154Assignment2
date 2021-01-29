#include "Car.h"
#include "Colors.h"
#include <algorithm>

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
		Rectangle(hdc, topLeft.GetIntX(), topLeft.GetIntY(), botRight.GetIntX(), botRight.GetIntY());
	} else 
	{
		Point topLeft(pos.x - width / 2, pos.y - length / 2);
		Point botRight(pos.x + width / 2, pos.y + length / 2);
		Rectangle(hdc, topLeft.GetIntX(), topLeft.GetIntY(), botRight.GetIntX(), botRight.GetIntY());
	}
}

Point Car::TopLeft(){
	int width = length / 2;
	if (IsHorizontal()) {
		return Point(pos.x - length / 2, pos.y - width / 2);
	}
	else {
		return Point(pos.x - width / 2, pos.y - length / 2);
	}
}

Point Car::BottomRight() {
	int width = length / 2;
	if (IsHorizontal()) {
		return Point(pos.x + length / 2, pos.y + width / 2);
	}
	else {
		return Point(pos.x + width / 2, pos.y + length / 2);
	}
}


bool Car::IsHorizontal()
{
	return direction.x != 0;
}

void Car::Update(int frameTime, HWND hWnd)
{
	MakeDecision();
	Point oldTopLeft = TopLeft();
	Point oldBottomRight = BottomRight();
	UpdatePosition(frameTime);

	Point newTopLeft = TopLeft();
	Point newBottomRight = BottomRight();

	Point xtremtopLeft = Point(oldTopLeft.x < newTopLeft.x? oldTopLeft.x: newTopLeft.x, 
		oldTopLeft.y < newTopLeft.y ? oldTopLeft.y : newTopLeft.y);

	Point xtrembottomRight = Point(oldBottomRight.x > newBottomRight.x ? oldBottomRight.x : newBottomRight.x,
		oldBottomRight.y > newBottomRight.y ? oldBottomRight.y : newBottomRight.y);
	const RECT rect{ xtremtopLeft.GetIntX(),xtremtopLeft.GetIntY(), xtrembottomRight.GetIntX(), xtrembottomRight.GetIntY() };
	InvalidateRect(hWnd, &rect,false);
}

void Car::MakeDecision()
{
	if (pos.DistanceTo(next->GetPos()) < 40 && next->Obstruct())
	{
		ChangeSpeed(-10);
	}
	else {
		ChangeSpeed(5);
	}
}

void Car::ChangeSpeed(double delta)
{
	double newSpeed = speed + delta;

	speed = std::clamp(newSpeed, 0, 16);
	speed = std::min(16.0, std::max(newSpeed, 0.0));
}

void Car::UpdatePosition(int frameTime)
{
	pos = (pos + direction * (speed * 10.0) * (frameTime / 1000.0));
}
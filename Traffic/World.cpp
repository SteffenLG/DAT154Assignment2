#include "World.h"



void World::Draw(HDC hdc, Palette palette) 
{
	HPEN pen = CreatePen(PS_NULL, 1, RGB(0, 0, 255));
	SelectObject(hdc, pen);
	DrawGrass(hdc, palette);
	DrawRoads(hdc, palette);
	DeleteObject(pen);
	controller->Draw(hdc, palette);
}

void World::DrawGrass(HDC hdc, Palette palette)
{
	HBRUSH grassBrush = palette.GetBrush(GrassGreen);
	SelectObject(hdc, grassBrush);
	Rectangle(hdc, 0, 0, width, height);
}

void World::DrawRoads(HDC hdc, Palette palette)
{
	HBRUSH asphaltBrush = palette.GetBrush(Asphalt);
	int centerX = width / 2;
	int centerY = height / 2;
	int laneWidth = 100;

	SelectObject(hdc, asphaltBrush);

	Rectangle(hdc, 0, centerY - laneWidth, width, centerY + laneWidth);
	Rectangle(hdc, centerX - laneWidth, 0, centerX + laneWidth, height);

	HPEN linePen = CreatePen(PS_DASH, laneWidth / 20, LineYellow);
	SelectObject(hdc, linePen);
	MoveToEx(hdc, centerX, 0, nullptr);
	LineTo(hdc, centerX, height);
	MoveToEx(hdc, 0, centerY, nullptr);
	LineTo(hdc, width, centerY);
	//SelectObject(hdc, pen)
	Rectangle(hdc,
		centerX - laneWidth,
		centerY - laneWidth,
		centerX + laneWidth,
		centerY + laneWidth);
}


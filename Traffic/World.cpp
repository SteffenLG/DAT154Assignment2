#include "World.h"



void World::Draw(HDC hdc, Palette& palette) 
{

	
	DrawGrass(hdc, palette);
	DrawRoads(hdc, &palette);

	controller->Draw(hdc, palette);
}

void World::Update() 
{
	//TODO gjøre dette basert på timer elns
	controller->ChangeLightState();
}

void World::DrawGrass(HDC hdc, Palette& palette)
{
	SelectObject(hdc, palette.InviPen);
	HBRUSH grassBrush = palette.GetBrush(GrassGreen);
	SelectObject(hdc, grassBrush);
	Rectangle(hdc, 0, 0, width, height);
}

void World::DrawRoads(HDC hdc, Palette* palette)
{
	SelectObject(hdc, palette->InviPen);
	HBRUSH asphaltBrush = palette->GetBrush(Asphalt);
	int centerX = width / 2;
	int centerY = height / 2;
	int laneWidth = 100;

	SelectObject(hdc, asphaltBrush);

	Rectangle(hdc, 0, centerY - laneWidth, width, centerY + laneWidth);
	Rectangle(hdc, centerX - laneWidth, 0, centerX + laneWidth, height);


	SelectObject(hdc, palette->LinePen);
	MoveToEx(hdc, centerX, 0, nullptr);
	LineTo(hdc, centerX, height);
	MoveToEx(hdc, 0, centerY, nullptr);
	LineTo(hdc, width, centerY);
	//SelectObject(hdc, pen);
	Rectangle(hdc,
		centerX - laneWidth,
		centerY - laneWidth,
		centerX + laneWidth,
		centerY + laneWidth);
	MoveToEx(hdc, centerX - laneWidth, centerY - laneWidth, nullptr);
	LineTo(hdc, centerX, centerY - laneWidth);
	MoveToEx(hdc, centerX - laneWidth, centerY, nullptr);
	LineTo(hdc, centerX - laneWidth, centerY + laneWidth);
	MoveToEx(hdc, centerX + laneWidth * 2, centerY - laneWidth, nullptr);
	LineTo(hdc, centerX + laneWidth * 2, centerY);
}

void World::InitController()
{
	int centerX = width / 2;
	int centerY = height / 2;
	int laneWidth = 100;
	int laneMid = laneWidth / 2;

	controller = new TrafficController(
		*new TrafficLight(centerX - laneMid, centerY - laneWidth, 80),
		*new TrafficLight(centerX + laneWidth, centerY - laneMid, 80),
		*new TrafficLight(centerX + laneMid, centerY + laneWidth, 80),
		*new TrafficLight(centerX - laneWidth, centerY + laneMid, 80)
	);
}
World::~World() {
	int i = 1;
}
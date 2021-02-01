#include "World.h"

World::World(int h, int w) 
{
	width = w;
	height = h;
	int centerX = width / 2;
	int centerY = height / 2;
	int laneWidth = 100;
	int laneMid = laneWidth / 2;

	northLight = new TrafficLight(centerX - laneMid, centerY - laneWidth, 80);
	eastLight  = new TrafficLight(centerX + laneMid, centerY + laneWidth, 80);
	southLight = new TrafficLight(centerX + laneWidth, centerY - laneMid, 80);
	westLight  = new TrafficLight(centerX - laneWidth, centerY + laneMid, 80);

	controller = new TrafficController(
		northLight,
		eastLight,
		southLight,
		westLight
	);
}

void World::Draw(HDC hdc, Palette& palette) 
{

	
	DrawGrass(hdc, palette);
	DrawRoads(hdc, palette);

	controller->Draw(hdc, palette);
}

void World::Update(HWND hWnd) 
{
	//TODO gjøre dette basert på timer elns
	controller->ChangeLightState();

	controller->Update(hWnd);
}

void World::DrawGrass(HDC hdc, Palette& palette)
{
	SelectObject(hdc, palette.InviPen);
	HBRUSH grassBrush = palette.GetBrush(GrassGreen);
	SelectObject(hdc, grassBrush);
	Rectangle(hdc, 0, 0, width, height);
}

void World::DrawRoads(HDC hdc, Palette& palette)
{
	SelectObject(hdc, palette.InviPen);
	HBRUSH asphaltBrush = palette.GetBrush(Asphalt);
	int centerX = width / 2;
	int centerY = height / 2;
	int laneWidth = 100;

	SelectObject(hdc, asphaltBrush);

	Rectangle(hdc, 0, centerY - laneWidth, width, centerY + laneWidth);
	Rectangle(hdc, centerX - laneWidth, 0, centerX + laneWidth, height);


	SelectObject(hdc, palette.LinePen);
	MoveToEx(hdc, centerX, 0, nullptr);
	LineTo(hdc, centerX, height);
	MoveToEx(hdc, 0, centerY, nullptr);
	LineTo(hdc, width, centerY);
	SelectObject(hdc, palette.InviPen);
	Rectangle(hdc,
		centerX - laneWidth,
		centerY - laneWidth,
		centerX + laneWidth,
		centerY + laneWidth);
	SelectObject(hdc, palette.WhiteLinePen);
	MoveToEx(hdc, centerX - laneWidth, centerY - laneWidth, nullptr);
	LineTo(hdc, centerX, centerY - laneWidth);
	MoveToEx(hdc, centerX - laneWidth, centerY, nullptr);
	LineTo(hdc, centerX - laneWidth, centerY + laneWidth);
	MoveToEx(hdc, centerX + laneWidth, centerY - laneWidth, nullptr);
	LineTo(hdc, centerX + laneWidth, centerY);
	MoveToEx(hdc, centerX, centerY + laneWidth, nullptr);
	LineTo(hdc, centerX + laneWidth, centerY + laneWidth);
	
}

World::~World() {
	int i = 1;
}
#pragma once
#include "framework.h"
#include "Palette.h"
#include "Colors.h"
#include "TrafficController.h"

class World
{
	int height;
	int width;
	
	TrafficController* controller;

	TrafficLight* northLight;
	TrafficLight* eastLight;
	TrafficLight* southLight;
	TrafficLight* westLight;
public:
	World(int h, int w);
	~World();
	void Draw(HDC, Palette&);
	void Update(HWND hWnd);
private:
	void DrawGrass(HDC, Palette&);
	void DrawRoads(HDC, Palette&);
};

/*
	$-----------------------------&-------------------$
*/
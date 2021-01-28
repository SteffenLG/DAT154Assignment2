#pragma once
#include "framework.h"
#include "Palette.h"
#include "Colors.h"
#include "TrafficController.h"

class World
{
	int height;
	int width;
	TrafficController *controller;
public:
	World(int h, int w) : height{ h }, width{ w }, controller{ nullptr } { InitController(); };
	~World();
	void Draw(HDC, Palette&);
	void Update();
private:
	void DrawGrass(HDC, Palette&);
	void DrawRoads(HDC, Palette&);
	void InitController();
};


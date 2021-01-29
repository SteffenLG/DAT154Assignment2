#pragma once
#include "TrafficLight.h"
#include "Palette.h"
#include "Road.h"

class TrafficController
{
public:
	TrafficLight northLight;
	TrafficLight southLight;
	TrafficLight eastLight;
	TrafficLight westLight;

	Road* westRoad;

	TrafficController(TrafficLight, TrafficLight, TrafficLight, TrafficLight);
	void Draw(HDC, Palette&);
	void ChangeLightState();
	void Update(HWND hWnd);
};


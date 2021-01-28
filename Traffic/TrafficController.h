#pragma once
#include "TrafficLight.h"
#include "Palette.h"

class TrafficController
{
public:
	TrafficLight northLight;
	TrafficLight southLight;
	TrafficLight eastLight;
	TrafficLight westLight;

	TrafficController(TrafficLight, TrafficLight, TrafficLight, TrafficLight);
	void Draw(HDC, Palette&);
	void ChangeLightState();
};


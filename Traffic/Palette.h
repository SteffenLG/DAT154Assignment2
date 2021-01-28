#pragma once
#include <map>
#include "framework.h"
#include "Colors.h"

class Palette
{
	std::map<COLORREF, HBRUSH> brushes;
public:
	Palette();
	~Palette();
	HBRUSH GetBrush(COLORREF);
	//HBRUSH GetRandomBrush();

	HBRUSH TrafficLightRedBrush;
	HBRUSH TrafficLightYellowBrush;
	HPEN InviPen;
	HPEN LinePen;
};


#pragma once
#include <map>
#include "framework.h"
#include "Colors.h"

class Palette
{
	std::map<COLORREF, HBRUSH> brushes;
public:
	Palette() : brushes{ } {
	InviPen = CreatePen(PS_NULL, 1, RGB(0, 0, 255));
	LinePen = CreatePen(PS_DASH, 100 / 20, LineYellow);
	};
	~Palette();
	HBRUSH& GetBrush(COLORREF);
	//HBRUSH GetRandomBrush();

	HPEN InviPen;
	HPEN LinePen;
};


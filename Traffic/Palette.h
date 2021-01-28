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

	HPEN InviPen;
	HPEN LinePen;
};


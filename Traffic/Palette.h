#pragma once
#include <map>
#include "framework.h"

class Palette
{
	std::map<COLORREF, HBRUSH> brushes;
public:
	Palette() : brushes{ } {};
	~Palette();
	HBRUSH GetBrush(COLORREF);
	//HBRUSH GetRandomBrush();
};


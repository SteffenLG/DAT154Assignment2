#pragma once
#include "framework.h"
#include "TrafficNode.h"
#include "Point.h"

class Car : public TrafficNode
{
	COLORREF color;

public:
	Car(Point p, Point d, double s, COLORREF c, int l) :
		TrafficNode(p, d, s, l),
		color{ c } {};
	bool obstruct() override;
};


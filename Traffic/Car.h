#pragma once
#include "framework.h"
#include "TrafficNode.h"
#include "Point.h"

class Car: public TrafficNode
{
	Point pos;
	Point direction; 
	double speed;
	COLORREF color;
	int length;

public:
	Car(Point p, Point d, double s, COLORREF c, int l);
	bool obstruct() override;
};


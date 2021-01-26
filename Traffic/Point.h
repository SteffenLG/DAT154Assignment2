#pragma once
#include <cmath>

class Point
{
public:
	double x;
	double y;
	Point(double, double);
	double DistanceTo(Point);
	Point operator+(Point);
	Point operator*(double);
};


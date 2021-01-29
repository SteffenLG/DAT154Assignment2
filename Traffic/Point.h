#pragma once
#include <cmath>

class Point
{
public:
	double x;
	double y;
	Point(double, double);
	int GetIntX();
	int GetIntY();
	double DistanceTo(Point);
	Point DirectionTo(Point);
	Point operator+(Point);
	Point operator*(double);
private:
	double Signum(double);
};


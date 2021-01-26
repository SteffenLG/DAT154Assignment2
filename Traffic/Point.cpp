#include "Point.h"

Point::Point(double x,  double y)
{
	this->x = x;
	this->y = y;
}

double Point::DistanceTo(Point other)
{
	 double a = this->x - other.x;
	 double b = this->y - other.y;
	 double hyp = std::sqrt(std::pow(a, 2) + std::pow(b, 2));
	 return hyp;
}

 Point Point::operator+(Point other)
 {
	 return Point(this->x + other.x, this->y + other.y);
 }

 Point Point::operator*(double scalar)
 {
	 return Point(this->x * scalar, this->y * scalar);
 }

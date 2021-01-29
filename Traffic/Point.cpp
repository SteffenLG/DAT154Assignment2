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

 int Point::GetIntX()
 {
	 return (int)x;
 }

 int Point::GetIntY()
 {
	 return (int)y;
 }

 Point Point::DirectionTo(Point other)
 {
	 double xDiff = this->x - other.x;
	 double yDiff = this->y - other.y;
	 
	 return Point(Signum(xDiff), Signum(yDiff));
 }

 double Point::Signum(double x)
 {
	 if (x > 0)
		 return 1;
	 if (x < 0)
		 return -1;
	 return 0;
 }
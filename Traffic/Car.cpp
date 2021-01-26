#include "Car.h"
#include "Colors.h"

Car::Car(Point p, Point d, double s, COLORREF c, int l) :
	pos{ p },
	direction{ d },
	speed{ s },
	color{ c },
	length{ l }
{};

bool Car::obstruct() {
	return true;
}

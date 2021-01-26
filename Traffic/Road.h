#pragma once

#include "stdlib.h"
#include "Point.h"
#include "Car.h"
#include <vector>
#include <queue>

class Road
{
	Point start;
	Point end;
	std::vector<Point> lightPos;
	std::vector<Road> next;
	std::queue<Car> cars;
public:
	Road(Point s, Point e) : start{ s }, end{ e }, lightPos{  }, next{ } {};
	Road(Point s, Point e, Road &n) : start{ s }, end{ e }, lightPos{ e }, next{ n } {};
	Road(Point s, Point e, Point l, Road &n) : start{ s }, end{ e }, lightPos{ l }, next{ n } {};


};


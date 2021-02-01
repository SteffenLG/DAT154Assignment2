#pragma once

#include "stdlib.h"
#include "Point.h"
#include "Car.h"
#include "TrafficLight.h"
#include <memory>

class Road
{
	Point start;
	Point end;
	TrafficNode startNode;
	TrafficNode endNode;
public:
	Road(Point s, Point e, TrafficLight *light) : 
		start{ s }, 
		end{ e }, 
		startNode{ TrafficNode(start, Point(0, 0), 0, 0) },
		endNode{ TrafficNode(end, Point(0, 0), 0, 0) } {
		startNode.SetNext(light);
		light->SetNext(endNode.GetNext());
	};
	void SpawnCar();
	void Draw(HDC hdc, Palette &palette);
	void Update(int frameTime, HWND hWnd);
private:
	void ManageList();
	COLORREF RandomColor();
};


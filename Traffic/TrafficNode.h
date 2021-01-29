#pragma once
#include "Point.h"

class TrafficNode
{
protected:
	Point pos;
	Point direction;
	double speed;
	int length;
	TrafficNode* next;
	TrafficNode(Point p, Point d, double s, int l) : 
		pos{ p }, direction{ d }, 
		speed{ s }, length{ l },
		next{ nullptr } {};
public:
	virtual bool Obstruct();
	void SetNext(TrafficNode* next);
	TrafficNode* GetNext();
	void Draw();
};


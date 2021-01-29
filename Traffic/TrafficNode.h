#pragma once
#include "Point.h"
#include "Palette.h"

class TrafficNode
{
protected:
	Point pos;
	Point direction;
	double speed;
	int length;
	TrafficNode* next;
	
	
public:
	virtual bool Obstruct();
	void SetNext(TrafficNode*);
	TrafficNode* GetNext();
	virtual void Draw(HDC hdc, Palette&);
	virtual void Update(int frameTime, HWND hWnd);
	virtual Point TopLeft();
	virtual Point BottomRight();

	TrafficNode(Point p, Point d, double s, int l) :
		pos{ p }, direction{ d },
		speed{ s }, length{ l },
		next{ nullptr } {};
	
};


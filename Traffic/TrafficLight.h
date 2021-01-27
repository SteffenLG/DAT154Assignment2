#pragma once

#include "framework.h"
#include "Colors.h"
#include "TrafficNode.h"
#include "Palette.h"

class TrafficLight 
{
public:
	enum State : int { RED = 1, REDYELLOW = 2, GREEN = 3, YELLOW = 4, OFF = 5 };
	TrafficLight(int x, int y, int height);
	void DrawLight(HDC hdc, Palette&);
	~TrafficLight();
	void SetState(State currentState);
	State GetState();
	bool obstruct();
	void CycleState();
private:
	State state;
	int left;
	int top;
	int width;
	int right;
	int bottom;
};


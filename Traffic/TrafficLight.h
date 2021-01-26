#pragma once

#include "framework.h"
#include "Colors.h"
#include "TrafficNode.h"

class TrafficLight 
{
public:
	enum State : int { RED = 1, REDYELLOW = 2, GREEN = 3, YELLOW = 4, OFF = 5 };
	TrafficLight(int x, int y, int height);
	void DrawLight(HDC hdc);
	~TrafficLight();
	void SetState(State currentState);
	State GetState();
	bool obstruct();
	void CycleState();
private:
	HBRUSH brushRed;
	HBRUSH brushBlack;
	HBRUSH brushYellow;
	HBRUSH brushGreen;
	HBRUSH brushGray;
	HPEN pen;
	State state;
	int left;
	int top;
	int width;
	int right;
	int bottom;
};


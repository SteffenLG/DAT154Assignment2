#pragma once

#include "framework.h"
#include "Colors.h"
#include "TrafficNode.h"
#include "Palette.h"
#include "TrafficLightStates.h"

class TrafficLight:public TrafficNode
{
public:
	TrafficLight(int x, int y, int height);
	void Draw(HDC hdc, Palette&) override;
	void Update(int frameTime, HWND hWnd) override;
	~TrafficLight();
	void SetState(State currentState);
	State GetState();
	bool Obstruct();
	void CycleState();
private:
	State state;
	int left;
	int top;
	int width;
	int right;
	int bottom;

};


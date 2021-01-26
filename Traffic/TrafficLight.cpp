#include "TrafficLight.h"

TrafficLight::TrafficLight(int x, int y, int height) {
	
	//lage brushes
	brushRed = CreateSolidBrush(TrafficLightRed);
	brushBlack = CreateSolidBrush(TraficLightBlack);
	brushYellow = CreateSolidBrush(TrafficLightYellow);
	brushGreen = CreateSolidBrush(TrafficLightGreen);
	brushGray = CreateSolidBrush(TrafficLightGray);
	pen = CreatePen(PS_NULL, 1, RGB(0, 0, 255));

	//definere størrelser på ting
	left = x;
	top = y;
	width = height / 3;
	right = left + width;
	bottom = top + height;

	//sette default state
	state = OFF;
	
	
}
TrafficLight::~TrafficLight() {
	DeleteObject(brushRed);
	DeleteObject(brushBlack);
	DeleteObject(brushYellow);
	DeleteObject(brushGreen);
	DeleteObject(brushGray);
	DeleteObject(pen);
}
void TrafficLight::DrawLight(HDC hdc) {
	int margin = (int) (width * 0.08);
	SelectObject(hdc, pen);
	SelectObject(hdc, brushBlack);

	Rectangle(hdc, left, top, right, bottom);
	//gray lights
	SelectObject(hdc, brushGray);
	
	//light 1
	Ellipse(hdc, left + margin, top + margin, right - margin, top + width - margin);
	//light 2
	Ellipse(hdc, left + margin, top + width + margin, right - margin, top + width * 2 - margin);
	//light 3
	Ellipse(hdc, left + margin, top + width * 2 + margin, right - margin, top + width * 3 - margin);
	switch (state) {
	case 1:
		//light 1 - red
		SelectObject(hdc, brushRed);
		Ellipse(hdc, left + margin, top + margin, right - margin, top + width - margin);
		break;
	case 2:
		//light 1 - red
		SelectObject(hdc, brushRed);
		Ellipse(hdc, left + margin, top + margin, right - margin, top + width - margin);
		//light 2 - yellow
		SelectObject(hdc, brushYellow);
		Ellipse(hdc, left + margin, top + width + margin, right - margin, top + width * 2 - margin);
		break;
	case 3:
		//light 3 - green
		SelectObject(hdc, brushGreen);
		Ellipse(hdc, left + margin, top + width * 2 + margin, right - margin, top + width * 3 - margin);
		break;
	case 4:
		//light 2 - yellow
		SelectObject(hdc, brushYellow);
		Ellipse(hdc, left + margin, top + width + margin, right - margin, top + width * 2 - margin);
		break;
	}
}

void TrafficLight::SetState(State state) {
	this->state = state;
}
#include "TrafficLight.h"
#include "TrafficLightStates.h"

TrafficLight::TrafficLight(int x, int y, int height) {
	
	//definere størrelser på ting
	left = x;
	top = y;
	width = height / 3;
	right = left + width;
	bottom = top + height;

	//sette default state
	state = State::OFF;
	
}
TrafficLight::~TrafficLight() {

}
void TrafficLight::DrawLight(HDC hdc, Palette& palette) {
	int margin = (int) (width * 0.08);
	SelectObject(hdc, palette.InviPen);
	SelectObject(hdc, palette.GetBrush(TrafficLightBlack));

	Rectangle(hdc, left, top, right, bottom);
	//gray lights
	SelectObject(hdc, palette.GetBrush(TrafficLightGray));
	
	//light 1
	Ellipse(hdc, left + margin, top + margin, right - margin, top + width - margin);
	//light 2
	Ellipse(hdc, left + margin, top + width + margin, right - margin, top + width * 2 - margin);
	//light 3
	Ellipse(hdc, left + margin, top + width * 2 + margin, right - margin, top + width * 3 - margin);
	switch (state) {
	case State(1):
		//light 1 - red
		SelectObject(hdc, palette.TrafficLightRedBrush);
		Ellipse(hdc, left + margin, top + margin, right - margin, top + width - margin);
		break;
	case State(2):
		//light 1 - red
		SelectObject(hdc, palette.TrafficLightRedBrush);
		Ellipse(hdc, left + margin, top + margin, right - margin, top + width - margin);
		//light 2 - yellow
		SelectObject(hdc, palette.TrafficLightYellowBrush);
		Ellipse(hdc, left + margin, top + width + margin, right - margin, top + width * 2 - margin);
		break;
	case State(3):
		//light 3 - green
		SelectObject(hdc, palette.GetBrush(TrafficLightGreen));
		Ellipse(hdc, left + margin, top + width * 2 + margin, right - margin, top + width * 3 - margin);
		break;
	case State(4):
		//light 2 - yellow
		SelectObject(hdc, palette.TrafficLightYellowBrush);
		Ellipse(hdc, left + margin, top + width + margin, right - margin, top + width * 2 - margin);
		break;
	}
}

void TrafficLight::SetState(State state) {
	this->state = state;
}

State TrafficLight::GetState() {
	return this->state;
}

bool TrafficLight::obstruct() {
	return this->state != State::GREEN;
}

void TrafficLight::CycleState()
{
	int currentState = (int)this->state;
	int nextState = (currentState % 4) + 1;
	this->state = State(nextState);
}
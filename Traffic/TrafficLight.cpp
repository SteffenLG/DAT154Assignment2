#include "TrafficLight.h"
#include "TrafficLightStates.h"

TrafficLight::TrafficLight(int x, int y, int height) :
	TrafficNode(Point(x, y), Point(0, 0), 0, height),
	left{ x },
	top{ y },
	width{ height / 3 },
	right{ left + width },
	bottom{ top + height },
	state{ State::OFF }
{};
TrafficLight::~TrafficLight() {

}
void TrafficLight::Draw(HDC hdc, Palette& palette) {
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
		SelectObject(hdc, palette.GetBrush(TrafficLightRed));
		Ellipse(hdc, left + margin, top + margin, right - margin, top + width - margin);
		break;
	case State(2):
		//light 1 - red
		SelectObject(hdc, palette.GetBrush(TrafficLightRed));
		Ellipse(hdc, left + margin, top + margin, right - margin, top + width - margin);
		//light 2 - yellow
		SelectObject(hdc, palette.GetBrush(TrafficLightYellow));
		Ellipse(hdc, left + margin, top + width + margin, right - margin, top + width * 2 - margin);
		break;
	case State(3):
		//light 3 - green
		SelectObject(hdc, palette.GetBrush(TrafficLightGreen));
		Ellipse(hdc, left + margin, top + width * 2 + margin, right - margin, top + width * 3 - margin);
		break;
	case State(4):
		//light 2 - yellow
		SelectObject(hdc, palette.GetBrush(TrafficLightYellow));
		Ellipse(hdc, left + margin, top + width + margin, right - margin, top + width * 2 - margin);
		break;
	}
}

void TrafficLight::Update(int frameTime, HWND hWnd) {
	const RECT rect{ left,top, right, bottom};
	InvalidateRect(hWnd, &rect, false);
}

void TrafficLight::SetState(State state) {
	this->state = state;
}

State TrafficLight::GetState() {
	return this->state;
}

bool TrafficLight::Obstruct() {
	return this->state != State::GREEN;
}

void TrafficLight::CycleState()
{
	int currentState = (int)this->state;
	int nextState = (currentState % 4) + 1;
	this->state = State(nextState);
}

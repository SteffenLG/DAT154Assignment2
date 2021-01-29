#include "TrafficController.h"

TrafficController::TrafficController(
	TrafficLight n,
	TrafficLight s,
	TrafficLight e,
	TrafficLight w
) : 
northLight{ n }, 
southLight{ s }, 
eastLight{ e }, 
westLight{ w } 
{
	northLight.SetState(State::RED);
	southLight.SetState(State::RED);
	eastLight.SetState(State::GREEN);
	westLight.SetState(State::GREEN);
};

void TrafficController::Draw(HDC hdc, Palette& palette)
{
	northLight.Draw(hdc, palette);
	southLight.Draw(hdc, palette);
	eastLight.Draw(hdc, palette);
	westLight.Draw(hdc, palette);
}

void TrafficController::ChangeLightState()
{
	northLight.CycleState();
	southLight.CycleState();
	eastLight.CycleState();
	westLight.CycleState();
}

void TrafficController::Update(HWND hWnd) {
	northLight.Update(17,hWnd);
	southLight.Update(17,hWnd);
	eastLight.Update(17,hWnd);
	westLight.Update(17,hWnd);
}
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
	eastLight.SetState(State::RED);
	westLight.SetState(State::RED);
};

void TrafficController::Draw(HDC hdc, Palette& palette)
{
	northLight.DrawLight(hdc, palette);
	southLight.DrawLight(hdc, palette);
	eastLight.DrawLight(hdc, palette);
	westLight.DrawLight(hdc, palette);
}

void TrafficController::ChangeLightState()
{
	northLight.CycleState();
	southLight.CycleState();
	eastLight.CycleState();
	westLight.CycleState();
}
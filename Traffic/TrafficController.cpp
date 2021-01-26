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
westLight{ w } {};

void TrafficController::Draw(HDC hdc, Palette palette)
{
	northLight.DrawLight(hdc);
	southLight.DrawLight(hdc);
	eastLight.DrawLight(hdc);
	westLight.DrawLight(hdc);
}

void TrafficController::ChangeLightState()
{
	northLight.CycleState();
	southLight.CycleState();
	eastLight.CycleState();
	westLight.CycleState();
}
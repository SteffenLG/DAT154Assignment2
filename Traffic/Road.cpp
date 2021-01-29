#include "Road.h"

void Road::SpawnCar()
{
	Car car(start, start.DirectionTo(end), 1, RandomColor(), 80);
	car.SetNext(startNode->GetNext());
	startNode->SetNext(&car);
}

void Road::Draw(HDC hdc, Palette &palette)
{
	TrafficNode* temp = startNode->GetNext();
	while (temp != endNode)
	{
		temp->Draw(hdc, palette);
		temp = temp->GetNext();
	}
}

void Road::Update(int frameTime, HWND hWnd)
{
	TrafficNode* temp = startNode->GetNext();
	while (temp != endNode)
	{
		temp->Update(frameTime, hWnd);
		temp = temp->GetNext();
	}
}
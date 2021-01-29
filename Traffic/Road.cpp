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

	ManageList();
}

void Road::ManageList()
{
	TrafficNode* temp = startNode;
	while (temp->GetNext() != endNode)
	{
		TrafficNode* next = temp->GetNext();
		TrafficNode* nextNext = temp->GetNext()->GetNext();
		if (next->Obstruct() && !nextNext->Obstruct()) 
		{
			double nextDistance = temp->GetPos().DistanceTo(next->GetPos());
			double nextNextDistance = temp->GetPos().DistanceTo(nextNext->GetPos());

			if (nextNextDistance < nextDistance) 
			{
				temp->SetNext(nextNext);
				next->SetNext(nextNext->GetNext());
				nextNext->SetNext(next);
			}
		}
		temp = temp->GetNext();
	}

	if (endNode->GetNext() != nullptr)
		endNode->SetNext(nullptr);
}


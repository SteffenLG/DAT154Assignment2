#include "Road.h"

void Road::SpawnCar()
{
	Car car(start, start.DirectionTo(end), 0, RandomColor(), 80);
	car.SetNext(startNode.GetNext());
	startNode.SetNext(&car);
}

void Road::Draw(HDC hdc, Palette &palette)
{
	TrafficNode* temp = startNode.GetNext();
	while (temp != &endNode)
	{
		temp->Draw(hdc, palette);
		temp = temp->GetNext();
	}
}

void Road::Update(int frameTime, HWND hWnd)
{
	TrafficNode* temp = startNode.GetNext();
	while (temp != &endNode)
	{
		temp->Update(frameTime, hWnd);
		temp = temp->GetNext();
	}

	ManageList();
}

void Road::ManageList()
{
	TrafficNode* prev = &startNode;
	TrafficNode* current = startNode.GetNext();
	TrafficNode* next = current->GetNext();

	while (current->GetNext() != &endNode)
	{
		double currentDistance = prev->GetPos().DistanceTo(current->GetPos());
		double nextDistance = prev->GetPos().DistanceTo(next->GetPos());

		if (currentDistance > nextDistance)
		{
			prev->SetNext(next);
			current->SetNext(next->GetNext());
			next->SetNext(current);
		}
	}
	/*while (temp->GetNext() != endNode)
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
	}*/

	if (endNode.GetNext() != nullptr)
		endNode.SetNext(nullptr);
}

COLORREF Road::RandomColor()
{
	int size = sizeof(CarColors) / sizeof(CarColors[0]);
	int randIndex = rand() % size;
	return CarColors[randIndex];
}

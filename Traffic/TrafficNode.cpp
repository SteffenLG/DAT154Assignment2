#include "TrafficNode.h"

bool TrafficNode::Obstruct()
{
	return false;
}

void TrafficNode::SetNext(TrafficNode* next)
{
	this->next = next;
}

TrafficNode* TrafficNode::GetNext()
{
	return this->next;
}

void TrafficNode::Draw(HDC hdc, Palette& palette)
{
	return;
}

void TrafficNode::Update(int frameTime, HWND hWnd)
{
	return;
}

Point TrafficNode::TopLeft() {
	return pos;
}

Point TrafficNode::BottomRight() {
	return pos;
}
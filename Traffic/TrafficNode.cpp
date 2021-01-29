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

void TrafficNode::Draw()
{
	return;
}
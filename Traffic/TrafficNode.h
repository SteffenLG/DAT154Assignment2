#pragma once

class TrafficNode
{
protected:
	TrafficNode* next;
	TrafficNode() : next{ nullptr } { };
public:
	virtual bool obstruct() = 0;
};


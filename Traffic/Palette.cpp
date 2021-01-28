#include "Palette.h"

Palette::Palette() {
	brushes = {};
	brushes[TrafficLightGreen] = CreateSolidBrush(TrafficLightGreen);
	brushes[TrafficLightBlack] = CreateSolidBrush(TrafficLightBlack);
	brushes[TrafficLightRed] = CreateSolidBrush(TrafficLightRed);
	brushes[TrafficLightYellow] = CreateSolidBrush(TrafficLightYellow);
	brushes[TrafficLightGray] = CreateSolidBrush(TrafficLightGray);
	brushes[GrassGreen] = CreateSolidBrush(GrassGreen);
	brushes[Asphalt] = CreateSolidBrush(Asphalt);
	brushes[LineYellow] = CreateSolidBrush(LineYellow);


	InviPen = CreatePen(PS_NULL, 1, RGB(0, 0, 255));
	LinePen = CreatePen(PS_DASH, 100 / 20, LineYellow);
};
HBRUSH Palette::GetBrush(COLORREF color) {

	return brushes[color];
	//std::map<COLORREF, HBRUSH>::iterator brushIter = brushes.find(color);
	/*
	if (brushIter != brushes.end()) {
		return brushIter->second;
	}
	else {
		HBRUSH brush = CreateSolidBrush(color);
		auto p = brushes.insert({ color, brush });
		return p.first->second;
	}
	*/
}

Palette::~Palette() {
	std::map<COLORREF, HBRUSH>::iterator iter = brushes.begin();
	for (; iter != brushes.end(); iter++) {
		DeleteObject(iter->second);
	}
}
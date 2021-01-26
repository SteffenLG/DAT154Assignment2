#include "Palette.h"

HBRUSH Palette::GetBrush(COLORREF color) {
	std::map<COLORREF, HBRUSH>::iterator brushIter = brushes.find(color);
	if (brushIter != brushes.end()) {
		return brushIter->second;
	}
	else {
		HBRUSH brush = CreateSolidBrush(color);
		brushes.insert({ color, brush });
		return brush;
	}
}

Palette::~Palette() {
	std::map<COLORREF, HBRUSH>::iterator iter = brushes.begin();
	for (; iter != brushes.end(); iter++) {
		DeleteObject(iter->second);
	}
}
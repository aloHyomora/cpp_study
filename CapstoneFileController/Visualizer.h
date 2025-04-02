#pragma once

#include <windows.h>
#include <string>
#include <vector>

class Visualizer {
public:
    static void DrawText(HDC hdc, const std::vector<std::wstring>& texts);
	static const std::vector<std::vector<std::wstring>> loadedFileNames;
};

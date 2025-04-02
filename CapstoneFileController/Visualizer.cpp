#include "Visualizer.h"
#include <map>

void Visualizer::DrawText(HDC hdc, const std::vector<std::wstring>& texts) {
    std::map<std::wstring, std::vector<std::wstring>> groupedTexts;
    
    // 그룹화
    for (const auto& text : texts) {
        if (!text.empty()) {
            size_t firstUnderscore = text.find(L'_');
            size_t secondUnderscore = text.find(L'_', firstUnderscore + 1);
            if (firstUnderscore != std::wstring::npos && secondUnderscore != std::wstring::npos) {
                std::wstring key = text.substr(firstUnderscore + 1, secondUnderscore - firstUnderscore - 1);
                groupedTexts[key].push_back(text);
            }
        }
    }

    int y = 10;
    for (const auto& group : groupedTexts) {
        ::TextOut(hdc, 10, y, group.first.c_str(), group.first.length());
        y += 20;
        for (const auto& text : group.second) {
            ::TextOut(hdc, 30, y, text.c_str(), text.length());
            y += 20;
        }
        y += 20; // 그룹 간 간격 추가
    }
}

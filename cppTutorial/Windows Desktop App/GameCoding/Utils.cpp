#include "pch.h"
#include "Utils.h"

void Utils::DrawText(HDC hdc, Pos pos, const wstring& str)
{
	::TextOut(hdc, static_cast<int>(pos.x), static_cast<int>(pos.y), str.c_str(), static_cast<int32>(str.size()));
}

void Utils::DrawRect(HDC hdc, Pos pos, int32 w, int32 h)
{
	::Rectangle(hdc, static_cast<int>(pos.x - w / 2), static_cast<int>(pos.y - h / 2), static_cast<int>(pos.x + w / 2), static_cast<int>(pos.y + h / 2));
}

void Utils::DrawCircle(HDC hdc, Pos pos, int32 radius)
{
	::Ellipse(hdc, static_cast<int>(pos.x - radius), static_cast<int>(pos.y - radius), static_cast<int>(pos.x + radius), static_cast<int>(pos.y + radius));
}

void Utils::DrawLine(HDC hdc, Pos from, Pos to)
{
	::MoveToEx(hdc, static_cast<int>(from.x), static_cast<int>(from.y), nullptr);
	::LineTo(hdc, static_cast<int>(to.x), static_cast<int>(to.y));
}

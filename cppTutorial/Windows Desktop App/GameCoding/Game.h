#pragma once
class Game
{
public:
	Game();
	~Game();

public:
	void Init(HWND hwnd);
	void Update();
	void Render();

private:
	HWND _hwnd = { };
	HDC _hdc = {};

private:
	// 더블 버퍼링
	RECT _rect;
	HDC _hdcBack = {};
	HBITMAP _bmpBack = {};
};
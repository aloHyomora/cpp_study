#include "pch.h"
#include "InputManager.h"

void InputManager::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_states.resize(KEY_TYPE_COUNT, KeyState::None);
}

void InputManager::Update()
{
	BYTE asciiKeys[KEY_TYPE_COUNT] = {};
	// key보드 상태 다 긁어오기이게 조금 더 빠름
	if (::GetKeyboardState(asciiKeys) == false)
		return;
	
	for (uint32 key = 0; key < KEY_TYPE_COUNT; key++)
	{
		// 키가 눌려 있으면 true
		if (asciiKeys[key] & 0x80) {
			KeyState& state = _states[key];

			// 이전 프레임에 키를 누른 상태라면 PRESS
			if (state == KeyState::Press || state == KeyState::Down)
				state = KeyState::Press;
			else
				state = KeyState::Down; // 처음 눌린 순간
		}
		else {
			KeyState& state = _states[key];

			// 이전 프레임에 키를 누른 상태라면 Up
			if (state == KeyState::Press || state == KeyState::Down)
				state = KeyState::Up;
			else
				state = KeyState::None;
		}
	}
	
	// Mouse
	::GetCursorPos(&_mousePos);	// 커서의 좌표를 알아본다.
	::ScreenToClient(_hwnd, &_mousePos);
}

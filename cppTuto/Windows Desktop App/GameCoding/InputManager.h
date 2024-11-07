#pragma once

enum class KeyType {
	LeftMouse = VK_LBUTTON,
	RightMouse = VK_RBUTTON,

	Up = VK_UP,
	Down = VK_DOWN,
	Left = VK_LEFT,
	Right = VK_RIGHT,
	SpaceBar = VK_SPACE,

	W = 'W',
	A = 'A',
	S = 'S',
	D = 'D'	
};

enum class KeyState {
	None,
	Press,
	Down,
	Up,
	End
};

enum {
	KEY_TYPE_COUNT = static_cast<int32>(UINT8_MAX) + 1,
	KEY_STATE_COUNT = static_cast<int32>(KeyState::End)
};

class InputManager
{
	DECLARE_SINGLE(InputManager);

public:
	void Init(HWND hwnd); // 현재 창이 선택되어 있는지 확인 용도로 받음
	void Update();

	// 맨 처음 눌렀을 때	
	bool GetButtonDown(KeyType key) { return GetState(key) == KeyState::Down; }

	// 누르고 있을 때
	bool GetButton(KeyType key) { return GetState(key) == KeyState::Press; }

	// 눌렀다가 땔 때
	bool GetButtonUp(KeyType key) { return GetState(key) == KeyState::Up; }

	POINT GetMousePos() { return _mousePos; }

private:
	KeyState GetState(KeyType key) { return _states[static_cast<uint8>(key)]; }
	
private:
	HWND _hwnd = 0;
	vector<KeyState> _states;
	POINT _mousePos;
};


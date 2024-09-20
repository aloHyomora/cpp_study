#include "Helper.h"
#include <Windows.h>


/// <summary>
/// 콘솔 입출력 코드
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>


MoveDir GMoveDir;
void HandleKeyInput() {
    if (::GetAsyncKeyState(VK_LEFT) & 0x8000)
        GMoveDir = LEFT;
    else if (::GetAsyncKeyState(VK_RIGHT) & 0x8000)
        GMoveDir = RIGHT;
    else if (::GetAsyncKeyState(VK_UP) & 0x8000)
        GMoveDir = UP;
    else if (::GetAsyncKeyState(VK_DOWN) & 0x8000)
        GMoveDir = DOWN;
    else
        GMoveDir = NONE;
}



void SetCursorPosition(int x, int y) {
    HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { (SHORT)x, (SHORT)y };
    ::SetConsoleCursorPosition(output, pos);
}

void SetCursorOnOff(bool visible) {
    HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    ::GetConsoleCursorInfo(output, &cursorInfo);
    cursorInfo.bVisible = visible;
    ::SetConsoleCursorInfo(output, &cursorInfo);
}


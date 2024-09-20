#pragma once

enum MoveDir {
    LEFT,
    RIGHT,
    UP,
    DOWN,
    NONE
};
void HandleKeyInput();

extern MoveDir GMoveDir;

void SetCursorPosition(int x, int y);
void SetCursorOnOff(bool visible);
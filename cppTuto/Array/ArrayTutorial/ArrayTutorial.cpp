#include <iostream>
using namespace std;

#include "Helper.h"
#include "Map.h"
#include "Player.h"
#include <Windows.h>


int main() {
    SetCursorOnOff(false);        

    while (true)
    {
        // 입력
        HandleKeyInput();
        // 로직
        HandleMove();
        // 출력
        PrintMap2D();
    }    
}
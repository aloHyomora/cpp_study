#include <iostream> 
using namespace std;
 
#include "Helper.h"
#include <Windows.h>

void SetCursorPosition(int x, int y){
        HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos = { (SHORT)x, (SHORT)y };
        ::SetConsoleCursorPosition(output, pos);
}

void SetCursorOnOff(bool visible){
        HANDLE output =  ::GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        ::GetConsoleCursorInfo(output, &cursorInfo);
        cursorInfo.bVisible = visible;
        ::SetConsoleCursorInfo(output, &cursorInfo);
}

int main(void)
{
        // SetCursorOnOff(false);


        return 0;
}
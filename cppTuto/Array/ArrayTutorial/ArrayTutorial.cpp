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
        // �Է�
        HandleKeyInput();
        // ����
        HandleMove();
        // ���
        PrintMap2D();
    }    
}
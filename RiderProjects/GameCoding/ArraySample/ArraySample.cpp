#include <iostream>
#include "Helper.h"
#include "Map.h"
#include "Player.h"
using namespace std;


int main()
{
    SetCursorOff(false);
  
    while (true)
    {
        // input
        HandleKeyInput();
        // logic
        HandleMove();
        // output
        PrintMap2D();
    }
}


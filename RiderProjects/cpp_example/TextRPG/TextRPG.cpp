#include "Player.h"
#include <iostream>

int main(int argc, char* argv[])
{
    Player player("Iron Man");
    char input;
    player.displayStatus();
    while (true)
    {
        cout << "Enter command (i for player Info, A for Attack, q to quit): ";
        cin >> input;

        if(input == 'i') player.displayStatus();
        else if(input == 'a') player.attack();
        else if(input == 'q') break;
        else cout << "Invalid command. Please try again.\n";
    }
    
    return 0;
}

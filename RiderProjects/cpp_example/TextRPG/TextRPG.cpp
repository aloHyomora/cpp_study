#include "Player.h"
#include <iostream>

#include "Monster.h"

int main(int argc, char* argv[])
{
    Player player("Iron Man");
    Monster monster("Goblin", 50, 5);

    unique_ptr<Item> items = make_unique<HealthPotion>("HP potion", 30);
    player.addItem(move(items));

    player.useItem(0);
    
    
    char input;
    
    while (true)
    {
        cout << "Enter command (i for player Info, M for monster Info, U for Inventory, A for Attack, q to quit): ";
        cin >> input;

        if(input == 'i') player.displayStatus();
        else if(input == 'm') monster.displayStatus();
        else if(input == 'a')
        {
            player.attack();
            monster.takeDamage(player.getAttackPower());
            if(monster.getHealth() == 0)
            {
                cout << " The monster is defeated!\n";
                break;
            }
        }
        else if(input == 'u')
        {
            int index;
            cout << "Enter item index to use: ";
            cin >> index;
            player.useItem(index);
        }
        else if(input == 'q') break;
        else cout << "Invalid command. Please try again.\n";

        // 몬스터의 턴
        monster.attack(player);
        if(player.getHealth() == 0)
        {
            cout << "The player is defeated!\n";
            break;
        }
    }
    
    return 0;
}

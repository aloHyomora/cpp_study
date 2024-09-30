#include <iostream>

using namespace std;
#include "Item.h"

// [시스템] 몬스터를 잡을 때, 아이템을 떨군다.
Item* DropItem() {
    if (rand() % 2 == 0) {
        Weapon* weapon = new Weapon();
        return weapon;
    }
    else
    {
        Armor* armor = new Armor();
        return armor;
    }
}

int main()
{
    srand((unsigned)time(0));

    for (int i = 0; i < 10; i++)
    {
        Item* item = DropItem(); 

        item->PrintInfo();

        // item->GetDamage() -> 사용 불가능 Weapon 타입이 아님.

    }

    std::cout << "Hello World!\n";
}


#include <iostream>

#include "Inventory.h"
#include "Item.h"

// [시스템] 몬스터를 잡을 때, 아이템을 떨군다.
Item* DropItem()
{
    if (rand() % 2 == 0)
    {
        Weapon* weapon = new Weapon();
        return weapon;
    }
    else
    {
        Armor* armor = new Armor();
        return armor;
    }
}

int main(int argc, char* argv[])
{
    Inventory inventory;
    
    srand((unsigned)time(0));

    for (int i =0; i<100; i++)
    {
        Item* item = DropItem();

        item -> PrintInfo();
        ItemType itemType = item ->GetItemType();

        if (itemType == IT_Weapon)
        {
            Weapon* weapon = (Weapon*)item;
            weapon->GetDamage();
        }
        else if (itemType == IT_Armor)
        {
            Armor* armor = (Armor*)item;
            armor->GetDefence();
        }
        
        // delete Item
        
    }
    
    return 0;
}

#include <iostream>

#include "Inventory.h"
#include "Item.h"

using namespace std;
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
    srand((unsigned)time(0));

    // 몬스터 처치, 아이템 드랍
    for (int i =0; i<100; i++)
    {
        Item* item = DropItem();
        item -> PrintInfo();

        if (Inventory::GetInstance()->AddItem(item))
        {
            cout << "Added Item to Inventory" << endl;
        }
        else
        {
            cout << "Failed to add Item" << endl;
            delete item;
        }


        
        /*ItemType itemType = item ->GetItemType();

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
        */
        
        // delete Item
        
    }

    // PK 당해서 랜덤으로 일부 아이템 드랍
    for (int i = 0; i < 20; i++)
    {
        int randIdx = rand() % MAX_SLOT;
        Item* item = Inventory::GetInstance()->GetItemSlot(randIdx);
        if (item && Inventory::GetInstance()->RemoveItem(item))
        {
            cout << "Removed Item" << endl;
        }
    }
    
    return 0;
}

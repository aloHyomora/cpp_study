#include "Inventory.h"

Inventory* Inventory::s_instance = nullptr;

Inventory::Inventory()
{
    for (int i = 0; i< MAX_SLOT; i++)
    {
        _itmes[i] = nullptr;
    }
}

Inventory::~Inventory()
{
    
}

bool Inventory::AddItem(Item* item)
{
    if(item == nullptr) return false;

    int emptySlot = FindEmptySlot();
    if(emptySlot < 0) return false;

    _itmes[emptySlot] = item;
    itemCount++;
}

bool Inventory::RemoveItem(Item* item)
{
    if(item == nullptr) return false;

    int slot = FindItemSlot(item);
    if(slot < 0 ) return false;

    _itmes[slot] = nullptr;
    itemCount--;
}

Item* Inventory::GetItemSlot(int slot)
{
    if(slot < 0 || slot >= MAX_SLOT)
        return nullptr;

    return _itmes[slot];
}

void Inventory::Clear()
{
    for (int i =0 ; i < MAX_SLOT; i++)
    {
        if(_itmes[i])
        {
            delete _itmes[i];
            _itmes[i] = nullptr;
        }
    }
    
}

Inventory* Inventory::GetInstance()
{
    if(s_instance == nullptr)
        s_instance = new Inventory();
    
    return s_instance;
}

int Inventory::FindEmptySlot()
{
    for (int i =0 ; i < MAX_SLOT; i++)
    {
        if(_itmes[i] == nullptr) return i;
    }
    return -1;
}

int Inventory::FindItemSlot(Item* item)
{
    for (int i = 0; i< MAX_SLOT; i++)
    {
        if(_itmes[i] == item)
            return i;
    }
    return -1;
}

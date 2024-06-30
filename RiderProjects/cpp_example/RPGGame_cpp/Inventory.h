#pragma once

#include "Item.h"

enum
{
    MAX_SLOT = 100
};

class Inventory
{
public:
    Inventory();
    ~Inventory();

    bool AddItem(Item* item);
    bool RemoveItem(Item* item);

    int FindEmptySlot();
    int FindItemSlot(Item* item);
private:
    int itemCount = 0;
    Item* _itmes[MAX_SLOT]; // 아이템의 주소를 가지는 포인터 배열
    
};

// Inventory inventory; 스택 영역에 올라감 (설계도 상 변수도 스택 영역에)

// Inventory inventory = new Inventory();
// 동적 할당, 힙 영역에 올라감

// main 밖에 있으면 메모리 영역에 올라감

// 포인터가 등장하면 null 체크 필수. 서버쪽은 공식이다.
#pragma once

#include "Item.h"

enum {
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
	Item* GetItemAtSlot(int slot);

	void Cleat();

	static Inventory* GetInstance();
private:
	Item* m_items[MAX_SLOT]; // 100개 공간을 미리 할당 받음.
	int m_itemCount = 0;

	static Inventory* s_instance;
};

// 클래스의 멤버 변수는 스택, 힙, 메모리 중 어디에 올라갈까?
// 
//int mainssss() {
//	Inventory inventory; // inventory 자체가 스택 영역에 올라감. 그러니 설계 상의 hp, mp 멤버 변수도 딸려 올라가게 된다.
//	Inventory* inventory = new Inventory(); // 동적 할당을 하는 순간 힙 영역에 얘가 올라가고 다만 스택 영역에는 이 포인터(주소)를 담고 있다.
//}
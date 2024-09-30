#pragma once

// #include "Item.h"
// ���� ����
class Item;  // -> ���߿� ������ ���̶�� �����ϰ�, .cpp�� #include �Ѵ�.
// ��� ���ϳ��� #include �ϴ� �� ��������. 
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

	void Clear();

	static Inventory* GetInstance();
private:
	Item* m_items[MAX_SLOT]; // 100�� ������ �̸� �Ҵ� ����.
	int m_itemCount = 0;

	static Inventory* s_instance;
};

// Ŭ������ ��� ������ ����, ��, �޸� �� ��� �ö󰥱�?
// 
//int mainssss() {
//	Inventory inventory; // inventory ��ü�� ���� ������ �ö�. �׷��� ���� ���� hp, mp ��� ������ ���� �ö󰡰� �ȴ�.
//	Inventory* inventory = new Inventory(); // ���� �Ҵ��� �ϴ� ���� �� ������ �갡 �ö󰡰� �ٸ� ���� �������� �� ������(�ּ�)�� ��� �ִ�.
//}
#include <iostream>
#include "Item.h"

using namespace std;
// ============================
//			Item
// ============================
Item::Item()
{
	int randValue = rand() % 100;

	if (randValue < 50) {
		m_rarity = IR_Normal;
	}
	else if (randValue < 80)
	{
		m_rarity = IR_Rare;
	}
	else
	{
		m_rarity = IR_Unique;
	}
}

Item::~Item()
{
}
void Item::PrintInfo()
{
	switch (m_rarity)
	{
	case IR_Normal:
		cout << "[희귀도] 일반" << endl;
		break;
	case IR_Rare:
		cout << "[희귀도] 레어" << endl;
		break;
	case IR_Unique:
		cout << "[희귀도] 유니크" << endl;
		break;
	default:
		break;
	}
}
// ============================
//			 Weapon
// ============================
Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}
void Weapon::PrintInfo()
{

	cout << "======================" << endl;
	cout << "[아이템 타입] : 무기" << endl;
	cout << "[공격력] : " << m_damage << endl;
	Item::PrintInfo();
	cout << "======================" << endl;
}
// ============================
//			 Armor
// ============================
Armor::Armor()
{
}

Armor::~Armor()
{
}

void Armor::PrintInfo()
{ 
	cout << "======================" << endl;
	cout << "[아이템 타입] : 방어구" << endl;
	cout << "[방어력] : " << m_defence << endl;
	Item::PrintInfo();
	cout << "======================" << endl;
}

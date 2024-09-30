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
		cout << "[��͵�] �Ϲ�" << endl;
		break;
	case IR_Rare:
		cout << "[��͵�] ����" << endl;
		break;
	case IR_Unique:
		cout << "[��͵�] ����ũ" << endl;
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
	cout << "[������ Ÿ��] : ����" << endl;
	cout << "[���ݷ�] : " << m_damage << endl;
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
	cout << "[������ Ÿ��] : ��" << endl;
	cout << "[����] : " << m_defence << endl;
	Item::PrintInfo();
	cout << "======================" << endl;
}

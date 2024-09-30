#include <iostream>
#include "Item.h"

using namespace std;
// ============================
//			Item
// ============================

Item::Item(ItemType itemType) : m_type(itemType) // �ڽ� Ŭ������ �����ڿ��� ��������� ��.
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
Weapon::Weapon() : Item(IT_Weapon)
{
	switch (m_rarity)
	{
	case IR_Normal:
		m_damage = 1 + rand() % 5;
		break;
	case IR_Rare:
		m_damage = 10 + rand() % 10;
		break;
	case IR_Unique:
		m_damage = 30 + rand() % 20;
		break;
	default:
		break;
	}
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
Armor::Armor() : Item(IT_Armor)
{
	switch (m_rarity)
	{
	case IR_Normal:
		m_defence = 1 + rand() % 5;
		break;
	case IR_Rare:
		m_defence = 10 + rand() % 10;
		break;
	case IR_Unique:
		m_defence = 30 + rand() % 20;
		break;
	default:
		break;
	}
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
#include "pch.h"
#include "Dragon.h"

Dragon::Dragon()
{
	cout << "Dragon ����" << endl;
	Init();
	PrintStatInfo();
}

Dragon::~Dragon()
{
	cout << "Dragon �Ҹ�" << endl;	
}

void Dragon::Init()
{
	m_stat.maxHp = 300;
	m_stat.hp = m_stat.maxHp;
	m_stat.attack = 20;
	m_stat.defense = 10;
	
}

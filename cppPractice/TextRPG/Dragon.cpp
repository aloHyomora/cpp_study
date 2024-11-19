#include "pch.h"
#include "Dragon.h"

Dragon::Dragon()
{
	cout << "Dragon »ý¼º" << endl;
	Init();
}

Dragon::~Dragon()
{
	cout << "Dragon ¼Ò¸ê" << endl;	
}

void Dragon::Init()
{
	{
		m_stat.maxHp = 300;
		m_stat.hp = m_stat.maxHp;
		m_stat.attack = 20;
		m_stat.defence = 10;
	}
}

void Dragon::Attack()
{
}

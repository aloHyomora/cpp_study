#include "pch.h"
#include "Goblin.h"

Goblin::Goblin()
{
	cout << "Goblin »ý¼º" << endl;
	Init();
	PrintStatInfo();
}

Goblin::~Goblin()
{
	cout << "Goblin ¼Ò¸ê" << endl;
}

void Goblin::Init()
{
	m_stat.maxHp = 50;
	m_stat.hp = m_stat.maxHp;
	m_stat.attack = 10;
	m_stat.defense = 5;

}

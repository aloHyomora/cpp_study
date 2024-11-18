#include "pch.h"
#include "Goblin.h"

Goblin::Goblin()
{
	cout << "Goblin »ý¼º" << endl;
	Init();
}

Goblin::~Goblin()
{
}

void Goblin::Init()
{
	{
		_stat.maxHp = 50;
		_stat.hp = _stat.maxHp;
		_stat.attack = 10;
		_stat.defence = 5;
	}
}

void Goblin::Attack()
{
}

#include "pch.h"
#include "Dragon.h"

Dragon::Dragon()
{
	cout << "Dragon »ý¼º" << endl;
	Init();
}

Dragon::~Dragon()
{
}

void Dragon::Init()
{
	{
		_stat.maxHp = 300;
		_stat.hp = _stat.maxHp;
		_stat.attack = 20;
		_stat.defence = 10;
	}
}

void Dragon::Attack()
{
}

#include "pch.h"
#include "Player.h"

Player::Player()
{
	cout << "Player »ý¼º" << endl;
	Init();
	PrintStatInfo();
}

Player::Player(ObjectType type) : _type(type)
{
}

Player::~Player()
{
}

void Player::Init()
{	
	{
		_stat.maxHp = 100 * _level;
		_stat.hp = _stat.maxHp;
		_stat.attack = 10 * _level;
		_stat.defence = 5 * _level;
	}
}

void Player::Attack()
{

}

void Player::LevelUp()
{
}

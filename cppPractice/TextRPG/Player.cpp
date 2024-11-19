#include "pch.h"
#include "Player.h"


Player::Player()
{
	cout << "Player 생성" << endl;
	Init();
	PrintStatInfo();
}

Player::~Player()
{
	cout << "Player 소멸" << endl;
}

void Player::Init()
{	
	// 타입 설정
	m_type = ObjectType::Player;

	// 스탯 설정
	{
		m_stat.maxHp = 100 * _level;
		m_stat.hp = m_stat.maxHp;
		m_stat.attack = 10 * _level;
		m_stat.defence = 5 * _level;
	}
}

void Player::Attack()
{

}

void Player::LevelUp()
{
}

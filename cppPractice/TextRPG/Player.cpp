#include "pch.h"
#include "Player.h"


Player::Player()
{
	cout << "Player ����" << endl;
	Init();
	PrintStatInfo();
}

Player::~Player()
{
	cout << "Player �Ҹ�" << endl;
}

void Player::Init()
{	
	// Ÿ�� ����
	m_type = ObjectType::Player;

	// ���� ����
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

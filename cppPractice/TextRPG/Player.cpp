#include "pch.h"
#include "Player.h"
#include "BattleManager.h"

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
	m_stat.maxHp = 100 * _level;
	m_stat.hp = m_stat.maxHp;
	m_stat.attack = 10 * _level;
	m_stat.defense = 5 * _level;
	
}

void Player::TakeDamage(int damage)
{
	// �θ� Ŭ�������� HP ���� ó��
	Object::TakeDamage(damage);

	if (m_stat.hp <= 0) {
		std::cout << "Player has been defeated!" << std::endl;
		GET_SINGLE(BattleManager)->m_battleInfo.isPlayerWin = false;
		GET_SINGLE(BattleManager)->m_battleInfo.isBattleEnd = true;
	}
}

void Player::LevelUp()
{
}

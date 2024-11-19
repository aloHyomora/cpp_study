#include "pch.h"
#include "Player.h"
#include "BattleManager.h"

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
	m_stat.maxHp = 100 * _level;
	m_stat.hp = m_stat.maxHp;
	m_stat.attack = 10 * _level;
	m_stat.defense = 5 * _level;
	
}

void Player::TakeDamage(int damage)
{
	// 부모 클래스에서 HP 감소 처리
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

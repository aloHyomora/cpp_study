#include "pch.h"
#include "Enemy.h"
#include "BattleManager.h"

Enemy::Enemy()
{
	cout << "Enemy 생성" << endl;
	Init();
	// PrintStatInfo();
}

Enemy::~Enemy()
{
	cout << "Enemy 소멸" << endl;
}

void Enemy::Init()
{
	m_type = ObjectType::Enemy;
}



void Enemy::TakeDamage(int damage)
{
	// 부모 클래스에서 HP 감소 처리
	Object::TakeDamage(damage);

	if (m_stat.hp <= 0) {
		std::cout << "Enemy has been defeated!" << std::endl;
		GET_SINGLE(BattleManager)->m_battleInfo.isPlayerWin = true;
		GET_SINGLE(BattleManager)->m_battleInfo.isBattleEnd = true;
	}
}

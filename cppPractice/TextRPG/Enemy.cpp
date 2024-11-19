#include "pch.h"
#include "Enemy.h"
#include "BattleManager.h"

Enemy::Enemy()
{
	cout << "Enemy ����" << endl;
	Init();
	// PrintStatInfo();
}

Enemy::~Enemy()
{
	cout << "Enemy �Ҹ�" << endl;
}

void Enemy::Init()
{
	m_type = ObjectType::Enemy;
}



void Enemy::TakeDamage(int damage)
{
	// �θ� Ŭ�������� HP ���� ó��
	Object::TakeDamage(damage);

	if (m_stat.hp <= 0) {
		std::cout << "Enemy has been defeated!" << std::endl;
		GET_SINGLE(BattleManager)->m_battleInfo.isPlayerWin = true;
		GET_SINGLE(BattleManager)->m_battleInfo.isBattleEnd = true;
	}
}

#include "pch.h"
#include "Enemy.h"

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

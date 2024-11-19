#include "pch.h"
#include "Enemy.h"

Enemy::Enemy()
{
	cout << "Enemy »ý¼º" << endl;
	Init();
	// PrintStatInfo();
}

Enemy::~Enemy()
{
	cout << "Enemy ¼Ò¸ê" << endl;
}

void Enemy::Init()
{
	m_type = ObjectType::Enemy;
}

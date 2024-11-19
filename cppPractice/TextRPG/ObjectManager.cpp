#include "pch.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Enemy.h"
#include "TurnHandler.h"

#include "Goblin.h"

void ObjectManager::Init()
{
	cout << "Init ObjectManager : ������ ������ ��ü ����" << endl;
	
	CreateObjects();
}

void ObjectManager::CreateObjects()
{
	cout << endl;
	cout << GET_SINGLE(TurnHandler)->GetRoundNum() << "����" << endl;
	cout << "������Ʈ ������..." << endl;

	// TOOD : �����ϰ� ����
	m_player = new Player();
	m_enemy = new Goblin();
}

Player* ObjectManager::GetPlayer()
{
	if (m_player) {
		return m_player;
	}
	return nullptr;
}

Enemy* ObjectManager::GetEnemy()
{
	if (m_enemy) {
		return m_enemy;
	}
	return nullptr;
}

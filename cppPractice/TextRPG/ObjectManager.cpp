#include "pch.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Enemy.h"
#include "TurnHandler.h"

#include "Goblin.h"

void ObjectManager::Init()
{
	cout << "Init ObjectManager : 전투에 참가할 객체 생성" << endl;
	
	CreateObjects();
}

void ObjectManager::CreateObjects()
{
	cout << endl;
	cout << GET_SINGLE(TurnHandler)->GetRoundNum() << "라운드" << endl;
	cout << "오브젝트 생성중..." << endl;

	// TOOD : 랜덤하게 변경
	m_player = new Player();
	m_enemy = new Goblin();
}

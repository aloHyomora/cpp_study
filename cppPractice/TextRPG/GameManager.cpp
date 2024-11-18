#include "pch.h"
#include "GameManager.h"
#include "ObjectManager.h"
#include "BattleManager.h"
#include "TurnHandler.h"

void GameManager::Init()
{
	cout << "Initializing Game..." << endl;

	GET_SINGLE(ObjectManager)->Init();
	GET_SINGLE(TurnHandler)->Init();
	
}

void GameManager::StartGameLogic()
{
	cout << "***Start Game***" << endl;

	GET_SINGLE(BattleManager)->StartBattle();
}

void GameManager::GameEnd()
{
	cout << "***End Game***" << endl;

}

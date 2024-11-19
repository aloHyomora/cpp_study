#include "pch.h"
#include "BattleManager.h"
#include "Player.h"
#include "Enemy.h"
#include "TurnHandler.h"
#include "ObjectManager.h"


void BattleManager::StartBattle()
{
	cout << "===== Start Battle =====" << endl;		

	while (!IsBattleOver()) {		
		m_battleInfo.totalRoundNum++; // 라운드 증가

		// 해당 라운드 싸우는 로직
		GET_SINGLE(TurnHandler)->TrunStart();
		
	}
	EndBattle();
}

void BattleManager::EndBattle()
{
	cout << endl;
	cout << "End Battle :" << "Total Round " << m_battleInfo.totalRoundNum << " =====" << endl;
	
	// 결과 출력 : 승, 패 여부
	GET_SINGLE(ObjectManager)->GetPlayer()->PrintStatInfo();
	GET_SINGLE(ObjectManager)->GetEnemy()->PrintStatInfo();

}

bool BattleManager::IsBattleOver()
{
	return m_battleInfo.isBattleEnd;
}

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
		m_battleInfo.totalRoundNum++; // ���� ����

		// �ش� ���� �ο�� ����
		GET_SINGLE(TurnHandler)->TrunStart();
		
	}
	EndBattle();
}

void BattleManager::EndBattle()
{
	cout << endl;
	cout << "End Battle :" << "Total Round " << m_battleInfo.totalRoundNum << " =====" << endl;
	
	// ��� ��� : ��, �� ����
	GET_SINGLE(ObjectManager)->GetPlayer()->PrintStatInfo();
	GET_SINGLE(ObjectManager)->GetEnemy()->PrintStatInfo();

}

bool BattleManager::IsBattleOver()
{
	return m_battleInfo.isBattleEnd;
}

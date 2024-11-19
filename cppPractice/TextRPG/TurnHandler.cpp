#include "pch.h"
#include "TurnHandler.h"
#include "GameManager.h"
#include "BattleManager.h"
#include "ObjectManager.h"
//#include "Object.h"
#include "Player.h"
#include "Enemy.h"

#include <random>

void TurnHandler::Init()
{
	_roundNum = 1;
	string input;
	// TODO : 사용자 입력 기다리고 들어오면 게임 로직 시작

	cout << "Enter a single word! if you want to start: ";
	cin >> input;

	cout << "You entered: " << input << endl;

	if (input.size() == 1) {
		GET_SINGLE(GameManager)->StartGameLogic();
	}
	
}

void TurnHandler::TrunStart()
{
	cout << endl;
	cout << "===== Round " << GET_SINGLE(BattleManager)->m_battleInfo.totalRoundNum << " Start =====" << endl;

	Player* player = GET_SINGLE(ObjectManager)->GetPlayer();
	Enemy* enemy = GET_SINGLE(ObjectManager)->GetEnemy();

	// 난수 생성
	random_device rd;								// 시드 생성
	mt19937 gen(rd());								// 난수 생성 엔진
	uniform_int_distribution<int> dist(0, 1);		// 균등 분포: 0 또는 1

	int data = dist(gen);
	if (data == 0) {
		cout << "해당 라운드는 플레이어의 선제 공격으로 시작됩니다..." << endl;		
		if (player->IsLive())
			player->Attack(enemy);
		else
		{
			cout << "Player 사망 라운드 종료..." << endl;
			return;
		}

		if (enemy->IsLive())
			enemy->Attack(player);
		else {
			cout << "Enemy 사망 라운드 종료..." << endl;
			return;
		}
		
	}
	else {
		cout << "해당 라운드는 Enemy의 선제 공격으로 시작됩니다...";

		if (enemy->IsLive())
			enemy->Attack(player);
		else
		{
			cout << "Enemy 사망 라운드 종료..." << endl;
			return;
		}

		if (player->IsLive())
			player->Attack(enemy);
		else
		{
			cout << "Player 사망 라운드 종료..." << endl;
			return;
		}
	}


}

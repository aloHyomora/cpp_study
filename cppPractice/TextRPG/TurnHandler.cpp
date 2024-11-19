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
	// TODO : ����� �Է� ��ٸ��� ������ ���� ���� ����

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

	// ���� ����
	random_device rd;								// �õ� ����
	mt19937 gen(rd());								// ���� ���� ����
	uniform_int_distribution<int> dist(0, 1);		// �յ� ����: 0 �Ǵ� 1

	int data = dist(gen);
	if (data == 0) {
		cout << "�ش� ����� �÷��̾��� ���� �������� ���۵˴ϴ�..." << endl;		
		if (player->IsLive())
			player->Attack(enemy);
		else
		{
			cout << "Player ��� ���� ����..." << endl;
			return;
		}

		if (enemy->IsLive())
			enemy->Attack(player);
		else {
			cout << "Enemy ��� ���� ����..." << endl;
			return;
		}
		
	}
	else {
		cout << "�ش� ����� Enemy�� ���� �������� ���۵˴ϴ�...";

		if (enemy->IsLive())
			enemy->Attack(player);
		else
		{
			cout << "Enemy ��� ���� ����..." << endl;
			return;
		}

		if (player->IsLive())
			player->Attack(enemy);
		else
		{
			cout << "Player ��� ���� ����..." << endl;
			return;
		}
	}


}

#pragma once
// ������ �����ϰ� �÷��̾�� ���� ���� ó���ϴ� ������ �����մϴ�.

class Player;
class Enemy;
class TurnHandler;

struct BattleInfo {
    bool isPlayerWin;
    bool isBattleEnd = false;
    int32 playerAttackNum = 0;
    int32 enemyAttackNum = 0;
    int32 totalRoundNum = 0; // ���� �ε��� : Player�� Enmey�� ���� ���忡 ���� �ο��.
};

class BattleManager
{
public:
    DECLARE_SINGLE(BattleManager);

    void StartBattle();                             // ���� ����
    void EndBattle();                               // ���� ����
    bool IsBattleOver();                            // ���� ���� Ȯ�� 

public:
    BattleInfo m_battleInfo;
};


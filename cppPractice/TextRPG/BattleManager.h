#pragma once
// ������ �����ϰ� �÷��̾�� ���� ���� ó���ϴ� ������ �����մϴ�.

class Player;
class Enemy;
class TurnHandler;
    
class BattleManager
{
public:
    DECLARE_SINGLE(BattleManager);

    void StartBattle();                             // ���� ����
    void EndBattle();                               // ���� ����
    bool IsBattleOver();                            // ���� ���� Ȯ�� 
};


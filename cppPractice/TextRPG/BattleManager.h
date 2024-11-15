#pragma once
// ������ �����ϰ� �÷��̾�� ���� ���� ó���ϴ� ������ �����մϴ�.

class BattleManager
{
public:
    void StartBattle(Player* player, Enemy* enemy); // ���� ����
    void EndBattle();                               // ���� ����
    bool IsBattleOver();                            // ���� ���� Ȯ��

private:
    Player* m_player;                               // �÷��̾� ��ü
    Enemy* m_enemy;                                 // �� ��ü
    TurnHandler m_turnHandler;                      // �� ���� ��ü	
};


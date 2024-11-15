#pragma once
// 전투를 시작하고 플레이어와 적의 턴을 처리하는 로직을 관리합니다.

class BattleManager
{
public:
    void StartBattle(Player* player, Enemy* enemy); // 전투 시작
    void EndBattle();                               // 전투 종료
    bool IsBattleOver();                            // 종료 조건 확인

private:
    Player* m_player;                               // 플레이어 객체
    Enemy* m_enemy;                                 // 적 객체
    TurnHandler m_turnHandler;                      // 턴 관리 객체	
};


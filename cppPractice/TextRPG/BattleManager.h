#pragma once
// 전투를 시작하고 플레이어와 적의 턴을 처리하는 로직을 관리합니다.

class Player;
class Enemy;
class TurnHandler;
    
class BattleManager
{
public:
    DECLARE_SINGLE(BattleManager);

    void StartBattle();                             // 전투 시작
    void EndBattle();                               // 전투 종료
    bool IsBattleOver();                            // 종료 조건 확인 
};


#pragma once
// 전투 중 플레이어와 적의 턴 순서를 관리합니다.

class TurnHandler
{
public:
	DECLARE_SINGLE(TurnHandler);

	void Init();
	void TrunStart();


	int GetRoundNum() { return _roundNum; }

private:
	int _roundNum = 0;		
};


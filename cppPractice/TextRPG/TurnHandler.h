#pragma once
// ���� �� �÷��̾�� ���� �� ������ �����մϴ�.

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


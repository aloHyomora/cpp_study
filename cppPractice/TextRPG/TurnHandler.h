#pragma once
// ���� �� �÷��̾�� ���� �� ������ �����մϴ�.

class TurnHandler
{
public:
	DECLARE_SINGLE(TurnHandler);

	void Init() { _roundNum = 1; }

	int GetRoundNum() { return _roundNum; }

private:
	int _roundNum = 0;		// ���� �ε���
};


#pragma once
// ���� �� �÷��̾�� ���� �� ������ �����մϴ�.

class TurnHandler
{
public:
	DECLARE_SINGLE(TurnHandler);

	void Init();

	int GetRoundNum() { return _roundNum; }

private:
	int _roundNum = 0;		// ���� �ε���
};


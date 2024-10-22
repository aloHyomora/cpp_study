#pragma once
#include "Vector.h"
#include <vector>
#include <queue>
class Board;

class Player
{
	enum {
		MOVE_TICK = 100 // 0.1�� ���� �̵��� �ǹ�
	};
public:

	void Init(Board* board);
	void Update(uint64 deltaTick);

	void SetPos(Pos pos) { m_pos = pos; }
	Pos GetPos() { return m_pos; }

	bool CanGo(Pos pos);

private:
	void CalculatePath_RightHand();
	void CalculatePath_BFS();

private:
	Pos		m_pos;
	int32	m_dir = DIR_UP;
	Board*  m_board = nullptr;

	// ���� �迭 (�÷��̾ �̵��� ��ǥ�� ����)
	vector<Pos>  m_path;			// {(1,1), (2,2), (3,3)}

	int32		 m_pathIndex = 0;
	uint64		 m_sumTick = 0;
};


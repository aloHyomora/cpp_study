#pragma once
#include "Vector.h"
#include <vector>
#include <queue>
class Board;

class Player
{
	enum {
		MOVE_TICK = 100 // 0.1초 마다 이동을 의미
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

	// 동적 배열 (플레이어가 이동할 좌표를 넣음)
	vector<Pos>  m_path;			// {(1,1), (2,2), (3,3)}

	int32		 m_pathIndex = 0;
	uint64		 m_sumTick = 0;
};


#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	m_pos = board->GetEnterPos();
	m_board = board;

	CalculatePath();
}

void Player::Update(uint64 deltaTick)
{
	if (m_pathIndex >= m_path.size())
		return;

	m_sumTick += deltaTick;

	if (m_sumTick >= MOVE_TICK) {
		m_sumTick = 0;
		// 이동
		m_pos = m_path[m_pathIndex];
		m_pathIndex++;
	}
}

bool Player::CanGo(Pos pos)
{
	TileType tileType = m_board->GetTileType(pos);
	return tileType == TileType::EMPTY;
}

// 우수법 (
void Player::CalculatePath()
{
	Pos pos = m_pos;

	m_path.clear();
	m_path.push_back(pos);

	// 목적지
	Pos dest = m_board->GetExitPos();		

	// Up에서 Left로 회전해야 한다 => enum Dir의 인덱스 증가하는 방향
	// 내가 바라보는 방향 기준 앞에 있는 좌표 구하기
	Pos front[4] =
	{
		Pos(-1, 0), // UP
		Pos(0, -1),	// LEFT
		Pos(1, 0),	// DOWN
		Pos(0, 1)	// RIGHT
	};	

#pragma region 없어도 되는 코드
	// 내가 바라보는 방향 기준 앞에 있는 좌표?
	Pos next = pos + front[m_dir];
	// 오른쪽 방향으로 90도 회전
	m_dir = (m_dir - 1) % DIR_COUNT;
	// 오른쪽 방향으로 90도 회전
	m_dir = (m_dir + 1) % DIR_COUNT;
#pragma endregion

	// 목적지 찾을 때까지
	while (pos != dest)
	{
		// 1. 현재 바라보는 방향 기준으로, 오른쪽(-1)으로 갈 수 있는지 확인.
		int32 newDir = (m_dir - 1 + DIR_COUNT) % DIR_COUNT;
		if (CanGo(pos + front[newDir]))
		{
			// 오른쪽 방향으로 90도 회전
			m_dir = newDir;

			// 앞으로 한 보 전진
			pos += front[m_dir];

			// 좌표 기록
			m_path.push_back(pos);
		}
		// 2. 현재 바라보는 방향을 기준으로 전진할 수 있는지 확인
		else if (CanGo(pos + front[m_dir]))
		{
			// 앞으로 한 보 전진
			pos += front[m_dir];

			// 좌표
			m_path.push_back(pos);
		}
		else
		{
			// 왼쪽 방향으로 90도 회전
			m_dir = (m_dir + 1) % DIR_COUNT;
		}
	}
}

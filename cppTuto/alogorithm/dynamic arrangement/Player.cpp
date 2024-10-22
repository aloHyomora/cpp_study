#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	m_pos = board->GetEnterPos();
	m_board = board;

	// CalculatePath_RightHand();
	CalculatePath_BFS();
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
void Player::CalculatePath_RightHand()
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

// 너비 우선 탐색
void Player::CalculatePath_BFS()
{
	// 정점, 간선을 어떻게 표현할 건지 결정
	// 간선 : 정점끼리의 연결
	// 이미 Map의 정보 만으로도 연결을 확인할 수 있으므로 신경쓰지 않는다.

	Pos pos = m_pos;
	
	// 목적지
	Pos dest = m_board->GetExitPos();	

	Pos front[4] =
	{
		Pos(-1, 0), // UP
		Pos(0, -1), // LEFT
		Pos(1, 0), // DOWN
		Pos(0, 1), // RIGHT
	};

	const int32 size = m_board->GetSize();

	// 어디를 다녀갔는지 discorvered, 2차원 배열
	vector<vector<bool>> discorvered(size, vector<bool>(size, false));
	
	// extra info (어떤 경로를..)
	// parent[y][x] = pos -> (y, x)는 Pos에 의해 발견됨. 
	vector<vector<Pos>> parent(size, vector<Pos>(size, Pos(-1, -1)));

	queue<Pos> q;
	q.push(pos);
	discorvered[pos.y][pos.x] = true;
	parent[pos.y][pos.x] = pos; // 시작점은 내 자신

	while (q.empty() == false)
	{
		pos = q.front();
		q.pop();

		// 목적지 도착
		if (pos == dest)
			break;

		for (int32 dir = 0; dir < DIR_COUNT; dir++)
		{
			Pos nextPos = pos + front[dir];
			// 갈 수 있는 지역이 맞는지 확인
			if (CanGo(nextPos) == false)
				continue;
			// 이미 다른 경로에 의해 발견한 지역인지 확인
			if (discorvered[nextPos.y][nextPos.x])
				continue;

			q.push(nextPos);
			discorvered[nextPos.y][nextPos.x] = true;
			parent[nextPos.y][nextPos.x] = pos; 
		}
	}

	m_path.clear();
	pos = dest;
	
	while (true)
	{
		m_path.push_back(pos);
		
		// 시작점
		if (pos == parent[pos.y][pos.x])
			break;

		pos = parent[pos.y][pos.x];
	}

	reverse(m_path.begin(), m_path.end());
}

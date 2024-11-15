#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	m_pos = board->GetEnterPos();
	m_board = board;

	// CalculatePath_RightHand();
	// CalculatePath_BFS();
	CalculatePath_AStar();
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

// BFS, 다익스트라는 목적지의 개념이 없음!
// 스타그래프트의 안개처럼? 
// 대각선 아래로 가는 게 합리적이다 라는 예측
// AStar: // 출구에 가까워질 수록 가산점을 준다.

// 채점
// - 입구에서부터 얼마나 떨어져 있는지?
// - 출구에서부터 얼마나 떨어져 있는지?

struct PQNode {
	PQNode(int32 f, int32 g, Pos pos) : f(f), g(g), pos(pos) {}

	bool operator<(const PQNode& other) const { return f < other.f; }
	bool operator>(const PQNode& other) const { return f > other.f; }

	int32 f; // f = g + h
	int32 g;
	Pos pos;
};
void Player::CalculatePath_AStar()
{
	// F = G + H
	// F = 최종 점수(작을수록 좋음)
	// G = 시작점에서 해당 좌표까지 이동하는데 드는 비용
	// H = 목적지에서 해당 좌표까지 이동하는데 드는 비용

	Pos start = m_pos;

	// 목적지
	Pos dest = m_board->GetExitPos();

	Pos front[] =
	{
		Pos(-1, 0), // UP
		Pos(0, -1), // LEFT
		Pos(1, 0), // DOWN
		Pos(0, 1), // RIGHT
		Pos(-1, -1), // UP_LEFT
		Pos(1, -1), // DOWN_LEFT
		Pos(1, 1), // DOWN_RIGHT
		Pos(-1, 1), // UP_RIGHT		
	};

	int32 cost[] = {
		10,
		10,
		10,
		10,
		14,
		14,
		14,
		14
	};

	const int32 size = m_board->GetSize();

	// best case 관리
	// best[y][x] -> 지금까지 (y,x)에 대해 가장 좋은 비용 (작을수록 좋음)
	vector<vector<int32>> best(size, vector<int32>(size, INT32_MAX));

	// Closed List -> closed[y][x] -> (y, x)에 방문을 했는지 여부
	// Option) 사실 best만 판별 가능
	vector<vector<bool>> closed(size, vector<bool>(size, false));

	// 부모 추적 용도
	vector<vector<Pos>> parent(size, vector<Pos>(size, Pos(-1, -1)));

	// 1) 예약 시스템 구현
	// 2) 뒤늦게 더 좋은 경로가 발견될 수 있음 -> 예외 처리!

	// OpenList : 지금까지 발견된 목록(방문한 게 아님)
	priority_queue<PQNode, vector<PQNode>, greater<PQNode>> pq;

	{
		int32 g = 0;
		int32 h = 10 * (abs(dest.y - start.y) + abs(dest.x - start.x));
		pq.push(PQNode(g + h, g, start));
		best[start.y][start.x] = g + h;
		parent[start.y][start.x] = start;
	}

	while (pq.empty() == false)
	{
		// 제일 좋은 후보를 찾는다.
		PQNode node = pq.top();
		pq.pop();

		// 동일한 좌표를 여러 경로로 찾아서
		// 더 빠른 경로로 인해서 이미 방문(closed)된 경우 스킵
		if (closed[node.pos.y][node.pos.x])
			continue;

		// 기껏 등록했더니만. 나보다 우수한 후보가 있다?
		if (best[node.pos.y][node.pos.x] < node.f)
			continue;

		// 방문
		closed[node.pos.y][node.pos.x] = true;

		if (node.pos == dest)
			break;

		for (int32 dir = 0; dir < 8; dir++)
		{
			Pos nextPos = node.pos + front[dir];
			// 갈 수 있는 지역은 맞는지 확인
			if (CanGo(nextPos) == false)
				continue;
			if (closed[nextPos.y][nextPos.x])
				continue;

			int32 g = node.g + cost[dir];
			int32 h = 10 * (abs(dest.y - nextPos.y) + abs(dest.x - nextPos.x));

			// 다른 경로에서 더 빠른 길을 찾았으면 스킵
			if (best[nextPos.y][nextPos.x] <= g + h)
				continue;

			// 예약 진행
			best[nextPos.y][nextPos.x] = g + h;
			pq.push(PQNode(g + h, g, nextPos));
			parent[nextPos.y][nextPos.x] = node.pos;
		}				
	}
	m_path.clear();
	Pos pos = dest;

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

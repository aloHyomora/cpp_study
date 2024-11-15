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
		// �̵�
		m_pos = m_path[m_pathIndex];
		m_pathIndex++;
	}
}

bool Player::CanGo(Pos pos)
{
	TileType tileType = m_board->GetTileType(pos);
	return tileType == TileType::EMPTY;
}

// ����� (
void Player::CalculatePath_RightHand()
{
	Pos pos = m_pos;

	m_path.clear();
	m_path.push_back(pos);

	// ������
	Pos dest = m_board->GetExitPos();		

	// Up���� Left�� ȸ���ؾ� �Ѵ� => enum Dir�� �ε��� �����ϴ� ����
	// ���� �ٶ󺸴� ���� ���� �տ� �ִ� ��ǥ ���ϱ�
	Pos front[4] =
	{
		Pos(-1, 0), // UP
		Pos(0, -1),	// LEFT
		Pos(1, 0),	// DOWN
		Pos(0, 1)	// RIGHT
	};	

#pragma region ��� �Ǵ� �ڵ�
	// ���� �ٶ󺸴� ���� ���� �տ� �ִ� ��ǥ?
	Pos next = pos + front[m_dir];
	// ������ �������� 90�� ȸ��
	m_dir = (m_dir - 1) % DIR_COUNT;
	// ������ �������� 90�� ȸ��
	m_dir = (m_dir + 1) % DIR_COUNT;
#pragma endregion

	// ������ ã�� ������
	while (pos != dest)
	{
		// 1. ���� �ٶ󺸴� ���� ��������, ������(-1)���� �� �� �ִ��� Ȯ��.
		int32 newDir = (m_dir - 1 + DIR_COUNT) % DIR_COUNT;
		if (CanGo(pos + front[newDir]))
		{
			// ������ �������� 90�� ȸ��
			m_dir = newDir;

			// ������ �� �� ����
			pos += front[m_dir];

			// ��ǥ ���
			m_path.push_back(pos);
		}
		// 2. ���� �ٶ󺸴� ������ �������� ������ �� �ִ��� Ȯ��
		else if (CanGo(pos + front[m_dir]))
		{
			// ������ �� �� ����
			pos += front[m_dir];

			// ��ǥ
			m_path.push_back(pos);
		}
		else
		{
			// ���� �������� 90�� ȸ��
			m_dir = (m_dir + 1) % DIR_COUNT;
		}
	}
}

// �ʺ� �켱 Ž��
void Player::CalculatePath_BFS()
{
	// ����, ������ ��� ǥ���� ���� ����
	// ���� : ���������� ����
	// �̹� Map�� ���� �����ε� ������ Ȯ���� �� �����Ƿ� �Ű澲�� �ʴ´�.

	Pos pos = m_pos;
	
	// ������
	Pos dest = m_board->GetExitPos();	

	Pos front[4] =
	{
		Pos(-1, 0), // UP
		Pos(0, -1), // LEFT
		Pos(1, 0), // DOWN
		Pos(0, 1), // RIGHT
	};

	const int32 size = m_board->GetSize();

	// ��� �ٳబ���� discorvered, 2���� �迭
	vector<vector<bool>> discorvered(size, vector<bool>(size, false));
	
	// extra info (� ��θ�..)
	// parent[y][x] = pos -> (y, x)�� Pos�� ���� �߰ߵ�. 
	vector<vector<Pos>> parent(size, vector<Pos>(size, Pos(-1, -1)));

	queue<Pos> q;
	q.push(pos);
	discorvered[pos.y][pos.x] = true;
	parent[pos.y][pos.x] = pos; // �������� �� �ڽ�

	while (q.empty() == false)
	{
		pos = q.front();
		q.pop();

		// ������ ����
		if (pos == dest)
			break;

		for (int32 dir = 0; dir < DIR_COUNT; dir++)
		{
			Pos nextPos = pos + front[dir];
			// �� �� �ִ� ������ �´��� Ȯ��
			if (CanGo(nextPos) == false)
				continue;
			// �̹� �ٸ� ��ο� ���� �߰��� �������� Ȯ��
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
		
		// ������
		if (pos == parent[pos.y][pos.x])
			break;

		pos = parent[pos.y][pos.x];
	}

	reverse(m_path.begin(), m_path.end());
}

// BFS, ���ͽ�Ʈ��� �������� ������ ����!
// ��Ÿ�׷���Ʈ�� �Ȱ�ó��? 
// �밢�� �Ʒ��� ���� �� �ո����̴� ��� ����
// AStar: // �ⱸ�� ������� ���� �������� �ش�.

// ä��
// - �Ա��������� �󸶳� ������ �ִ���?
// - �ⱸ�������� �󸶳� ������ �ִ���?

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
	// F = ���� ����(�������� ����)
	// G = ���������� �ش� ��ǥ���� �̵��ϴµ� ��� ���
	// H = ���������� �ش� ��ǥ���� �̵��ϴµ� ��� ���

	Pos start = m_pos;

	// ������
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

	// best case ����
	// best[y][x] -> ���ݱ��� (y,x)�� ���� ���� ���� ��� (�������� ����)
	vector<vector<int32>> best(size, vector<int32>(size, INT32_MAX));

	// Closed List -> closed[y][x] -> (y, x)�� �湮�� �ߴ��� ����
	// Option) ��� best�� �Ǻ� ����
	vector<vector<bool>> closed(size, vector<bool>(size, false));

	// �θ� ���� �뵵
	vector<vector<Pos>> parent(size, vector<Pos>(size, Pos(-1, -1)));

	// 1) ���� �ý��� ����
	// 2) �ڴʰ� �� ���� ��ΰ� �߰ߵ� �� ���� -> ���� ó��!

	// OpenList : ���ݱ��� �߰ߵ� ���(�湮�� �� �ƴ�)
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
		// ���� ���� �ĺ��� ã�´�.
		PQNode node = pq.top();
		pq.pop();

		// ������ ��ǥ�� ���� ��η� ã�Ƽ�
		// �� ���� ��η� ���ؼ� �̹� �湮(closed)�� ��� ��ŵ
		if (closed[node.pos.y][node.pos.x])
			continue;

		// �ⲯ ����ߴ��ϸ�. ������ ����� �ĺ��� �ִ�?
		if (best[node.pos.y][node.pos.x] < node.f)
			continue;

		// �湮
		closed[node.pos.y][node.pos.x] = true;

		if (node.pos == dest)
			break;

		for (int32 dir = 0; dir < 8; dir++)
		{
			Pos nextPos = node.pos + front[dir];
			// �� �� �ִ� ������ �´��� Ȯ��
			if (CanGo(nextPos) == false)
				continue;
			if (closed[nextPos.y][nextPos.x])
				continue;

			int32 g = node.g + cost[dir];
			int32 h = 10 * (abs(dest.y - nextPos.y) + abs(dest.x - nextPos.x));

			// �ٸ� ��ο��� �� ���� ���� ã������ ��ŵ
			if (best[nextPos.y][nextPos.x] <= g + h)
				continue;

			// ���� ����
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

		// ������
		if (pos == parent[pos.y][pos.x])
			break;

		pos = parent[pos.y][pos.x];
	}

	reverse(m_path.begin(), m_path.end());
}

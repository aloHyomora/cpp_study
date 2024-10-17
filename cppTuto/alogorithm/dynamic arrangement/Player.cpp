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
void Player::CalculatePath()
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

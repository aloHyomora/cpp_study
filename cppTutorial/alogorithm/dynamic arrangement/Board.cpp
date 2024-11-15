#include "pch.h"
#include "Board.h"
#include "Player.h"
const char* TILE = "��";

Board::Board()
{
}

Board::~Board()
{
}

void Board::Init(int32 size, Player* player)
{
	m_size = size;
	m_player = player;

	GenerateMap();
}


void Board::Render()
{
	ConsoleHelper::SetCursorPosition(0, 0);
	ConsoleHelper::ShowConsoleCursor(false);

	for (int32 y = 0; y < 25; y++)
	{
		for (int32 x = 0; x < 25; x++)
		{
			ConsoleColor color = GetTileColor(Pos(y, x));
			ConsoleHelper::SetCursorColor(color);
			cout << TILE;
		}
		cout << endl;
	}
}

// Binary Tree �̷� ���� �˰���
// -Mazes For Programmers
void Board::GenerateMap()
{
	for (int32 y = 0; y < m_size; y++)
	{
		for (int32 x = 0; x < m_size; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				m_tile[y][x] = TileType::WALL;
			else
				m_tile[y][x] = TileType::EMPTY;
		}
	}

	// �������� ���� Ȥ�� �Ʒ��� ���� �մ� �۾�
	for (int32 y = 0; y < m_size; y++)
	{
		for (int32 x = 0; x < m_size; x++)
		{
			// ���̸� ��ŵ
			if (x % 2 == 0 || y % 2 == 0)
				continue;
			
			// ��ǥ ����
			if (y == m_size - 2 && x == m_size - 2)
				continue;

			// �ϴ� ���� : ���� ������ �մ´�.
			if (y == m_size - 2) {
				m_tile[y][x + 1] = TileType::EMPTY;
				continue;
			}

			// ���� ���� : �ϴ� �������� �մ´�.
			if (x == m_size - 2) {
				m_tile[y+1][x] = TileType::EMPTY;
				continue;
			}

			// 1/2 Ȯ���� �Ʒ� Ȥ�� ���� �� �ձ� 
			const int32 randValue = ::rand() % 2;
			if (randValue == 0)
				m_tile[y][x + 1] = TileType::EMPTY;
			else
				m_tile[y + 1][x] = TileType::EMPTY;
		}
	}
}

TileType Board::GetTileType(Pos pos)
{
	if (pos.x < 0 || pos.x >= m_size)
		return TileType::NONE;
	if (pos.y < 0 || pos.y >= m_size)
		return TileType::NONE;

	return m_tile[pos.y][pos.x];
}

ConsoleColor Board::GetTileColor(Pos pos)
{
	if (m_player && m_player->GetPos() == pos)
		return ConsoleColor::YELLOW;
	if (GetExitPos() == pos)
		return ConsoleColor::BLUE;

	TileType tileType = GetTileType(pos);

	switch (tileType)
	{	
	case TileType::EMPTY:
		return ConsoleColor::GREEN;		
	case TileType::WALL:
		return ConsoleColor::RED;
	default:
		break;
	}

	return ConsoleColor::RED;
}

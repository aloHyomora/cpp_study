#include "pch.h"
#include "Board.h"
#include "Player.h"
const char* TILE = "■";

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

// Binary Tree 미로 생성 알고리즘
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

	// 랜덤으로 우측 혹은 아래로 길을 뚫는 작업
	for (int32 y = 0; y < m_size; y++)
	{
		for (int32 x = 0; x < m_size; x++)
		{
			// 벽이면 스킵
			if (x % 2 == 0 || y % 2 == 0)
				continue;
			
			// 목표 지점
			if (y == m_size - 2 && x == m_size - 2)
				continue;

			// 하단 도달 : 우측 방향을 뚫는다.
			if (y == m_size - 2) {
				m_tile[y][x + 1] = TileType::EMPTY;
				continue;
			}

			// 우측 도달 : 하단 방향으로 뚫는다.
			if (x == m_size - 2) {
				m_tile[y+1][x] = TileType::EMPTY;
				continue;
			}

			// 1/2 확률로 아래 혹은 왼쪽 벽 뚫기 
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

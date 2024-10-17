#pragma once
#include "ConsoleHelper.h"

// enum -> ����� ����� ���, define�� ���� ����� �ƴϴ�.
enum {
	BOARD_MAX_SIZE = 100
};

enum class TileType {
	NONE =0,
	EMPTY,
	WALL
};

class Player;
// ��ũ���� �׸� ���� ǥ���Ѵ�.
class Board
{
public:
	Board();
	~Board();

	void Init(int32 size, class Player* player);
	void Render();

	void			GenerateMap();
	TileType		GetTileType(Pos pos);
	ConsoleColor	GetTileColor(Pos pos);

	Pos				GetEnterPos() { return Pos(1, 1); }
	Pos				GetExitPos() { return Pos(m_size - 2, m_size - 2); }

private:
	TileType	m_tile[BOARD_MAX_SIZE][BOARD_MAX_SIZE];
	int32		m_size = 0;
	Player*		m_player = nullptr;
};


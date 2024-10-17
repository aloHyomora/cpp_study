#pragma once
#include "ConsoleHelper.h"

// enum -> 상수를 만드는 방법, define은 좋은 방법은 아니다.
enum {
	BOARD_MAX_SIZE = 100
};

enum class TileType {
	NONE =0,
	EMPTY,
	WALL
};

class Player;
// 스크린에 그릴 맵을 표현한다.
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


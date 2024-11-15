#include "pch.h"
#include "Vector.h"

#include "Board.h"
#include "Player.h"

Board board;
Player player;

#include "Stack.h"
int main()
{
    ::srand(static_cast<uint32>(time(nullptr)));

	board.Init(25, &player);
	player.Init(&board);

	uint64 lastTick = 0;

	while (true)
	{
#pragma region 프레임 관리
		// Player야 지난 프레임부터 00 초 지났어~
		const uint64 currentTick = ::GetTickCount64();
		const uint64 deltaTick = currentTick - lastTick;
		lastTick = currentTick;
#pragma endregion

		// 입력

		// 로직
		player.Update(deltaTick);

		// 렌더링
		board.Render();
	}
}

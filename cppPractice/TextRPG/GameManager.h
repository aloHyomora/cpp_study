#pragma once

// GameManger는 게임의 전체 흐름(초기화, 실행, 종료)을 관리합니다.

class GameManager
{
public:
	// DECLARE_SINGLE(GameManager); 싱글톤 사용이 필요없어 보임


public:
	void Init();
	void StartGameLogic();
	
	// TOOD : Game 종료 시에 메모리 정리
	void GameEnd();
	
};


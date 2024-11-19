#pragma once
class Player;
class Enemy;

class ObjectManager
{
public:
	DECLARE_SINGLE(ObjectManager);

	void Init();

	void CreateObjects();

	Player* GetPlayer();
	Enemy* GetEnemy();

private:
	Player* m_player;                               // ÇÃ·¹ÀÌ¾î °´Ã¼
	Enemy* m_enemy;                                 // Àû °´Ã¼
};


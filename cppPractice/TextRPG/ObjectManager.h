#pragma once
class Player;
class Enemy;

class ObjectManager
{
public:
	DECLARE_SINGLE(ObjectManager);

	void Init();

	void CreateObjects();

private:
	Player* m_player;                               // �÷��̾� ��ü
	Enemy* m_enemy;                                 // �� ��ü
};


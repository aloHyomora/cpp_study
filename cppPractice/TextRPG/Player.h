#pragma once
#include "Object.h"
class Player :	public Object
{
public:	
	Player();
	~Player() override;

public:
	void Init();
	void Attack();
	void LevelUp();

private:
	int _level = 1;
	int _exp = 0;
	int _maxExp = 100;
};


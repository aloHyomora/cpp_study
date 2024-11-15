#pragma once
#include "Enemy.h"
class Goblin :	public Enemy
{
public:
	Goblin();
	virtual ~Goblin();

public:
	virtual void Init() override;
	virtual void Attack() override;

};


#pragma once
#include "Object.h"

struct Reward {
	int exp = 10;
	// Item* item;
};

class Enemy :	public Object
{
public:
	Enemy();
	virtual ~Enemy();

public:
	virtual void Init() abstract;
	
	void TakeDamage(int damage) override;
	Reward GetReward() { return _reward; }


protected:	
	Reward _reward;	
};


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
	virtual void Attack() abstract;
	Reward GetReward() { return _reward; }


protected:
	Stat _stat;
	Reward _reward;	
};


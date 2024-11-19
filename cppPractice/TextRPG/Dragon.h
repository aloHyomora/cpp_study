#pragma once
#include "Enemy.h"
class Dragon : public Enemy
{
public:
	Dragon();
	virtual ~Dragon();

public:
	virtual void Init() override;
};


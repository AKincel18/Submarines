#pragma once
#include "Enemy_boat.h"
class Enemy2 : public Enemy_boat<Enemy2> // 200x40
{

public:
	Enemy2();
	void create();
};

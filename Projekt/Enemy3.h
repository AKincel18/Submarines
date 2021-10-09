#pragma once
#include "Enemy_boat.h"
class Enemy3 : public Enemy_boat<Enemy3> // 225x40
{
public:
	Enemy3();
	void create();
};

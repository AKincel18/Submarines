#pragma once
#include "Enemy_boat.h"
class Enemy1 :public Enemy_boat<Enemy1>  //135x40 -> dimensions
{
public:
	Enemy1();
	void create();
};

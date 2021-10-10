#include "Enemy1.h"

Enemy1::Enemy1()
{
	xe1 = Enemy_boat<Enemy1>::x;
	ye1 = Enemy_boat<Enemy1>::y;
}
void Enemy1::create()
{
	for (int i = 0; i < 3; i++)
	{
		Enemy1 *e = new Enemy1();
		vec.push_back(*e);
	}
}
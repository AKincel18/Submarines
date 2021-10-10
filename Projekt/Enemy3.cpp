#include "Enemy3.h"

Enemy3::Enemy3()
{
	xe1 = Enemy_boat<Enemy3>::x;
	ye1 = Enemy_boat<Enemy3>::y;
}
void Enemy3::create()
{
	for (int i = 0; i < 1; i++)
	{
		Enemy3 *e = new Enemy3();
		vec.push_back(*e);
	}
}

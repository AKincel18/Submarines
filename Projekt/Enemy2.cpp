#include "Enemy2.h"

Enemy2::Enemy2()
{
	xe1 = Enemy_boat<Enemy2>::x;
	ye1 = Enemy_boat<Enemy2>::y;
}
void Enemy2::create()
{
	for (int i = 0; i < 2; i++)
	{
		Enemy2 *e = new Enemy2();
		vec.push_back(*e);

	}
}

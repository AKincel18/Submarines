#include "MainBoat.h"

MainBoat::MainBoat() {}
MainBoat::MainBoat(int xx, int yy)
{
	x = xx;
	y = yy;
}
void MainBoat::set(int xx, int yy)
{
	x = xx;
	y = yy;
}
void MainBoat::show()
{

	if (key[0] == true) //w lewo
		al_draw_tinted_bitmap(boat, al_map_rgb(153, 217, 234), x, y, 0);
	else  // w prawo
		al_draw_tinted_bitmap(boat, al_map_rgb(153, 217, 234), x, y, 1);
}
void MainBoat::show_Dead()
{
	if (key[0] == true)
		al_draw_tinted_bitmap(boat2, al_map_rgb(153, 217, 234), x, y, 0);
	else
		al_draw_tinted_bitmap(boat2, al_map_rgb(153, 217, 234), x, y, 1);

}
void MainBoat::movement()
{
	if (key[0] == true && x>8) //w lewo
		x = x - 10 * move_level;
	if (key[1] == true && x<1255) // w prawo
		x = x + 10 * move_level;
}
void MainBoat::life()
{
	int first = 0;
	for (int i = 0; i < lifes; i++)
	{
		al_draw_tinted_bitmap(boat, al_map_rgb(153, 217, 234), first, 0, 0);
		first += 165;
	}
}
int MainBoat::getX()
{
	return x;
}
int MainBoat::getY()
{
	return y;
}
void MainBoat::add_life()
{
	if (!dodano)
	{
		lifes++;
		dodano = true;
	}
}
int MainBoat::getLife()
{
	return lifes;
}
void MainBoat::utrata_zycia()
{
	lifes--;
}
bool MainBoat::GAMEOVER()
{
	if (lifes == 0)
		return true;
	else
		return false;
}
void MainBoat::reset_NEW()
{
	lifes = 3;
	resetPOINTS();
	dodano = false;
}
void MainBoat::reset_bottle_and_move()
{
	dodano = false;
	move_level = 0;
	key[0] = true; key[1] = false;//lewy, prawy
}
void MainBoat::move(bool dir)
{
	switch (dir)
	{
	case 0://lewo
		if (key[0] == true)
		{
			if (move_level < 3)
				move_level++;
		}
		else
			move_level = 1;
		key[0] = true; key[1] = false;
		break;
	case 1: //prawo
		if (key[1] == true)
		{
			if (move_level < 3)
				move_level++;

		}
		else
			move_level = 1;
		key[1] = true; key[0] = false;
	}
}
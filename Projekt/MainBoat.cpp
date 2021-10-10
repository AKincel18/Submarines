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

	if (key[0] == true) //left
		al_draw_tinted_bitmap(boat, al_map_rgb(153, 217, 234), x, y, 0);
	else  //right
		al_draw_tinted_bitmap(boat, al_map_rgb(153, 217, 234), x, y, 1);
}

void MainBoat::show_dead()
{
	if (key[0] == true)
		al_draw_tinted_bitmap(dead_boat, al_map_rgb(153, 217, 234), x, y, 0);
	else
		al_draw_tinted_bitmap(dead_boat, al_map_rgb(153, 217, 234), x, y, 1);

}

void MainBoat::movement()
{
	if (key[0] == true && x > 8) //left
		x = x - 10 * move_level;
	if (key[1] == true && x < 1255) // right
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
	if (!added)
	{
		lifes++;
		added = true;
	}
}

int MainBoat::getLife()
{
	return lifes;
}

void MainBoat::lost_life()
{
	lifes--;
}

bool MainBoat::game_over()
{
	if (lifes == 0)
		return true;
	else
		return false;
}

void MainBoat::reset_new()
{
	lifes = 3;
	reset_points();
	added = false;
}

void MainBoat::reset_bottle_and_move()
{
	added = false;
	move_level = 0;
	key[0] = true; key[1] = false;
}

void MainBoat::move(bool dir)
{
	switch (dir)
	{
	case 0://left
		if (key[0] == true)
		{
			if (move_level < 3)
				move_level++;
		}
		else
			move_level = 1;
		key[0] = true; key[1] = false;
		break;
	case 1: //right
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
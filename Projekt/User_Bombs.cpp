#include "User_Bombs.h"
#include <vector>
using namespace std;
User_Bombs::User_Bombs()
{
	xB = GameObject::x;
	yB = GameObject::y;
}
void User_Bombs::add(MainBoat *mb)
{
	if (user_bombs_coords.size() < 10) //add bomb to vector is possible
	{
		coords w;
		w.xB = mb->getX() + 55; //shot bomb from bottom of boat
		w.yB = mb->getY() + 40;
		user_bombs_coords.push_back(w);
		mb->sub_point();
	}
}
void User_Bombs::movement()
{
	for (int it = 0; it < user_bombs_coords.size(); it++)
	{
		if (user_bombs_coords[it].yB > 760) //remove bomb
		{
			user_bombs_coords.erase(user_bombs_coords.begin() + it);
		}
		else
			user_bombs_coords[it].yB += 10; //bomb is falling

	}
}
void User_Bombs::show()
{
	for (vector <coords>::iterator it = user_bombs_coords.begin(); it != user_bombs_coords.end(); it++)
	{
		{
			al_draw_bitmap(bomb, it->xB, it->yB, 0);
		}
	}
}
void User_Bombs::left()
{
	first_life = 1375;
	for (int i = 0; i < max - user_bombs_coords.size(); i++)
	{
		al_draw_bitmap(bomb, first_life, 0, 0);
		first_life -= 20;
	}
}

vector <GameObject::coords> User_Bombs::getV()
{
	return user_bombs_coords;
}
void User_Bombs::remove(int bomb_number)
{
	if (bomb_number < max && user_bombs_coords.size() != 0 && user_bombs_coords.size() > bomb_number)
	{
		user_bombs_coords.erase(user_bombs_coords.begin() + bomb_number);
	}
}
void User_Bombs::reset()
{
	user_bombs_coords.clear();
}

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
	if (vec.size() < 10) //jesli dostepne bomby to dodaj do wektora
	{
		wsp w;
		w.xB = mb->getX() + 55; // poprawka zeby walil bomby spod okretu
		w.yB = mb->getY() + 40;	//jw
		vec.push_back(w);
		mb->subPOINTS();
	}
}
void User_Bombs::movement()
{
	for (int it = 0; it < vec.size(); it++)
	{
		if (vec[it].yB > 760) //jesli w dno to usuwaj
		{
			vec.erase(vec.begin() + it);
		}
		else
			vec[it].yB += 10; // bomba spada

	}
}
void User_Bombs::show()
{
	for (vector <wsp>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		{
			al_draw_bitmap(bomb, it->xB, it->yB, 0);
		}
	}
}
void User_Bombs::left()
{
	first = 1375;
	for (int i = 0; i < max - vec.size(); i++)
	{
		al_draw_bitmap(bomb, first, 0, 0);
		first -= 20;
	}
}

vector <GameObject::wsp> User_Bombs::getV()
{
	return vec;
}
void User_Bombs::usun(int ktory)
{
	if (ktory < max && vec.size() != 0)
	{
		vec.erase(vec.begin() + ktory);
	}
}
void User_Bombs::reset()
{
	vec.clear();
}

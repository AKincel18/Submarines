#include "Enemy_boat.h"
#include <vector>
 
using namespace std;

template <class typ>
Enemy_boat<typ>::Enemy_boat() {}
template <class typ>
Enemy_boat<typ>::Enemy_boat(int xx, int yy)

{
	x = xx;
	y = yy;
}
template <class typ>
void Enemy_boat<typ>::kalibracja()
{
	if (class_name == "class Enemy1")
	{
		zawroc = 1265; dlugosc = 135; kalibruj = 55;
	}
	else if (class_name == "class Enemy2")
	{
		zawroc = 1200; dlugosc = 200; kalibruj = 90;
	}

	else if (class_name == "class Enemy3")
	{
		zawroc = 1175; dlugosc = 225; kalibruj = 102;
	}
}
template <class typ>
void Enemy_boat<typ>::movement()
{
	for (vector <typ>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (it->xe1 + 5 >= zawroc) //zawracanie-> plyn w lewo
		{
			it->xe1 -= 10;
			it->dir = 1;
		}
		else if (it->xe1 <= 0) //zawracanie-> plyn w prawo
		{
			it->xe1 += 10;
			it->dir = 0;
		}
		else
		{
			switch (it->dir)
			{
			case 0:
				it->xe1 += 10;
				break;
			case 1:
				it->xe1 -= 10;
				break;
			}
		}

	}
}

template <class typ>
int Enemy_boat<typ>::get_hit()
{
	return hit;
}
template <class typ>
void Enemy_boat<typ>::set_hit()
{
	hit = max;
}
template <class typ>
void Enemy_boat<typ>::collision(vector <wsp> bU, MainBoat *mb) //bomba usera, a enemy
{
	set_hit();
	movement();
	for (int it = 0; it < vec.size(); it++)
	{
		for (int i = 0; i < bU.size(); i++)
		{
			if ((vec[it].xe1 <= bU[i].xB + 18 && vec[it].xe1 + dlugosc >= bU[i].xB) && bU[i].yB + 30 >= vec[it].ye1  && bU[i].yB + 30 <= vec[it].ye1 + 40)
			{
				//trafiony
				hit = i;
				if (class_name == "class Enemy1")
					mb->addPOINTS(10);
				else if (class_name == "class Enemy2")
					mb->addPOINTS(20);
				else if (class_name == "class Enemy3")
					mb->addPOINTS(50);

				vec.erase(vec.begin() + it);

				if (vec.size() == 0)
				{
					break;
				}
				if (it != 0)
					it--;
			}

		}
	}
}
template <class typ>
void Enemy_boat<typ>::show()
{
	if (vec.size() != 0)
	{
		if (class_name == "class Enemy1")
		{
			for (vector <typ>::iterator it = vec.begin(); it != vec.end(); it++)
			{
				al_draw_tinted_bitmap(enemy1, al_map_rgb(0, 0, 255), it->xe1, it->ye1, it->dir);
			}
		}
		else if (class_name == "class Enemy2")
		{
			for (vector <typ>::iterator it = vec.begin(); it != vec.end(); it++)
			{
				al_draw_tinted_bitmap(enemy2, al_map_rgb(0, 0, 255), it->xe1, it->ye1, it->dir);
			}
		}
		else if (class_name == "class Enemy3")
		{
			for (vector <typ>::iterator it = vec.begin(); it != vec.end(); it++)
			{
				al_draw_tinted_bitmap(enemy3, al_map_rgb(0, 0, 255), it->xe1, it->ye1, it->dir);
			}
		}
	}
}

template <class typ>
void Enemy_boat<typ>::add_bomb()
{
	if (vec.size() != 0)
	{
		wsp2 pom;
		for (vector <typ>::iterator it = vec.begin(); it != vec.end(); it++)
		{
			pom.x = it->xe1 + kalibruj;
			pom.y = it->ye1;
			w.push_back(pom);
		}
	}
}
template <class typ>
bool Enemy_boat<typ>::movement_bomb()//int xU)
{
	for (int it = 0; it < w.size(); it++)
	{
		if (w[it].y < 150) //jesli w 'brzeg'
		{
			w.erase(w.begin() + it);
		}
		else
		{
			w[it].y -= 10;
		}
	}
	return false;
}

template <class typ>
void Enemy_boat<typ>::show_bombs()
{
	for (vector <wsp2>::iterator it = w.begin(); it != w.end(); it++)
	{
		al_draw_bitmap(b, it->x, it->y, 0);
		al_convert_mask_to_alpha(b, al_map_rgb(0, 0, 255));//przezroczyste tlo bomby
	}
}
template <class typ>
int Enemy_boat<typ>::get_hit_main()
{
	return hit_main;
}
template <class typ>
void Enemy_boat<typ>::set_hit_main()
{
	hit_main = max;
}
template <class typ>
void Enemy_boat<typ>::remove(vector <wsp> bU, MainBoat *mb)
{
	set_hit_main();
	for (int it = 0; it < w.size(); it++)
	{
		for (int it2 = 0; it2 < bU.size(); it2++)
		{
			if (bU[it2].xB + 18 >= w[it].x && bU[it2].xB <= w[it].x + 20 && bU[it2].yB + 30 >= w[it].y  && bU[it2].yB + 30 <= w[it].y + 20)
			{
				w.erase(w.begin() + it);
				it--;

				mb->addPOINTS(5);
				hit_main = it2;
				//return it2;

			}
		}
	}

}
template <class typ>
bool Enemy_boat<typ>::NextLevel()
{
	if (w.empty() && vec.empty())
		return true;
	else
		return false;
}

template <class typ>
void Enemy_boat<typ>::reset()
{
	vec.clear();
	w.clear();
	
}
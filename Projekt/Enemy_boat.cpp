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
void Enemy_boat<typ>::calibrate()
{
	if (class_name == "class Enemy1")
	{
		back = 1265; length = 135; calibration = 55;
	}
	else if (class_name == "class Enemy2")
	{
		back = 1200; length = 200; calibration = 90;
	}

	else if (class_name == "class Enemy3")
	{
		back = 1175; length = 225; calibration = 102;
	}
}
template <class typ>
void Enemy_boat<typ>::movement()
{
	for (vector <typ>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (it->xe1 + 5 >= back) //turning back -> go to the left
		{
			it->xe1 -= 10;
			it->dir = 1;
		}
		else if (it->xe1 <= 0) // turning back->go to the right
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
void Enemy_boat<typ>::collision(vector <coords> bU, MainBoat *mb)
{
	set_hit();
	movement();
	for (int it = 0; it < vec.size(); it++)
	{
		for (int i = 0; i < bU.size(); i++)
		{
			if ((vec[it].xe1 <= bU[i].xB + 18 && vec[it].xe1 + length >= bU[i].xB) && bU[i].yB + 30 >= vec[it].ye1  && bU[i].yB + 30 <= vec[it].ye1 + 40)
			{
				//hit
				hit = i;
				if (class_name == "class Enemy1")
					mb->add_points(10);
				else if (class_name == "class Enemy2")
					mb->add_points(20);
				else if (class_name == "class Enemy3")
					mb->add_points(50);

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
		enemy_bomb_coords pom;
		for (vector <typ>::iterator it = vec.begin(); it != vec.end(); it++)
		{
			pom.x = it->xe1 + calibration;
			pom.y = it->ye1;
			enemy_bombs_coords.push_back(pom);
		}
	}
}
template <class typ>
bool Enemy_boat<typ>::movement_bomb()
{
	for (int it = 0; it < enemy_bombs_coords.size(); it++)
	{
		if (enemy_bombs_coords[it].y < 150)
		{
			enemy_bombs_coords.erase(enemy_bombs_coords.begin() + it);
		}
		else
		{
			enemy_bombs_coords[it].y -= 10;
		}
	}
	return false;
}

template <class typ>
void Enemy_boat<typ>::show_bombs()
{
	for (vector <enemy_bomb_coords>::iterator it = enemy_bombs_coords.begin(); it != enemy_bombs_coords.end(); it++)
	{
		al_draw_bitmap(b, it->x, it->y, 0);
		al_convert_mask_to_alpha(b, al_map_rgb(0, 0, 255));
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
void Enemy_boat<typ>::remove(vector <coords> bomb_user_coords, MainBoat *main_boat)
{
	set_hit_main();
	for (int it = 0; it < enemy_bombs_coords.size(); it++)
	{
		for (int it2 = 0; it2 < bomb_user_coords.size(); it2++)
		{
			if (bomb_user_coords[it2].xB + 18 >= enemy_bombs_coords[it].x && bomb_user_coords[it2].xB <= enemy_bombs_coords[it].x + 20 && 
				bomb_user_coords[it2].yB + 30 >= enemy_bombs_coords[it].y  && bomb_user_coords[it2].yB + 30 <= enemy_bombs_coords[it].y + 20)
			{
				enemy_bombs_coords.erase(enemy_bombs_coords.begin() + it);
				it--;


				main_boat->add_points(5);
				hit_main = it2;
				if (it < 0)
				{
					break;
				}

			}
		}
	}

}
template <class typ>
bool Enemy_boat<typ>::next_level()
{
	if (enemy_bombs_coords.empty() && vec.empty())
		return true;
	else
		return false;
}

template <class typ>
void Enemy_boat<typ>::reset()
{
	vec.clear();
	enemy_bombs_coords.clear();
	
}
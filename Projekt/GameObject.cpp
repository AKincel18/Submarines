#include "GameObject.h"
#include <vector>

using namespace std;
GameObject::GameObject() {}

bool GameObject::check_collision()
{
	for (int it = 0; it < user_bombs_coords.size(); it++)
	{
		if ((xO + 25 <= user_bombs_coords[it].xB + 18 && xO + 75 >= user_bombs_coords[it].xB) && (user_bombs_coords[it].yB + 30 >= yO))
		{
			user_bombs_coords.erase(user_bombs_coords.begin() + it);
			return true;
		}
	}
	return false;
}
bool GameObject::is_dead(int xU)
{

	for (vector<enemy_bomb_coords>::iterator it = enemy_bombs_coords.begin(); it != enemy_bombs_coords.end(); it++)
	{
		if (it->x >= xU && it->x <= xU + 145 && it->y <= 143)
		{
			return true;
		}
	}
	return false;

}
bool GameObject::new_life(int xU)
{
	if ((xO - 20 >= xU && xO <= xU + 145 && yBottle <= 145 && yBottle >= 130))
		return true;
	else
		return false;
}
int GameObject::get_points()
{
	return points;
}
void GameObject::reset_points()
{
	points = 0;
}
void GameObject::add_points(int _points)
{
	points += _points;
}
void GameObject::sub_point()
{
	points--;
}
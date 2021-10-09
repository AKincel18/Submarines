#include "GameObject.h"
#include <vector>

using namespace std;
GameObject::GameObject() {}

bool GameObject::CheckCollision()
{
	for (int it = 0; it < vec.size(); it++)
	{
		if ((xO + 25 <= vec[it].xB + 18 && xO + 75 >= vec[it].xB) && (vec[it].yB + 30 >= yO))
		{
			vec.erase(vec.begin() + it);
			return true;
		}
	}
	return false;
}
bool GameObject::Dead(int xU)
{

	for (vector<wsp2>::iterator it = w.begin(); it != w.end(); it++)
	{
		if (it->x >= xU && it->x <= xU + 145 && it->y <= 143)
		{
			//w.erase(w.begin() + it); //nie jest konieczne bo i tak wszystko od nowa
			return true;
		}
	}
	return false;

}
bool GameObject::NewLife(int xU)
{
	if ((xO - 20 >= xU && xO <= xU + 145 && yBottle <= 145 && yBottle >= 130))
		return true;
	else
		return false;
}
int GameObject::getPOINTS()
{
	return POINTS;
}
void GameObject::resetPOINTS()
{
	POINTS = 0;
}
void GameObject::addPOINTS(int ile)
{
	POINTS += ile;
}
void GameObject::subPOINTS()
{
	POINTS--;
}
#pragma once
#include <vector>
class GameObject 
{
protected:
	int x, y;
	int live;
	int xB, yB; // user's bombs
	int	max = 10; //max levels, todo
	int points = 0;
	//USER BOMB
	struct coords {
		int xB, yB;
	};
	std::vector <coords> user_bombs_coords;

	//octopus coords
	int xO = 500, yO = 710;			   
	int yBottle = yO;

	//Bomb enemy
	struct enemy_bomb_coords {
		int x, y;
	};
	std::vector <enemy_bomb_coords> enemy_bombs_coords;
public:
	GameObject();
	bool check_collision();
	bool is_dead(int xU);
	bool new_life(int xU);
	int get_points();
	void reset_points();
	void add_points(int points);
	void sub_point();
};
#pragma once
#include <vector>
class GameObject 
{
protected:
	int x, y;
	int live;
	int xB, yB, // bomby usera
		max = 10; //max dopasowac pozniej do poziomu
	int POINTS = 0;
	//USER BOMB
	struct wsp {
		int xB, yB;
	};
	std::vector <wsp> vec;

	//wspolrzedne octopusa
	int xO = 500,//rand() % 1298, //losowanie w poziomie
		yO = 710;			   //zeby na piasku byl
	int yBottle = yO;

	//Bomb enemy
	struct wsp2 {
		int x, y;
	};
	std::vector <wsp2> w;
public:
	GameObject();
	bool CheckCollision();
	bool Dead(int xU);
	bool NewLife(int xU);
	int getPOINTS();
	void resetPOINTS();
	void addPOINTS(int ile);
	void subPOINTS();
};
#pragma once
#include "GameObject.h"
#include "MainBoat.h"
#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <ctime>
#include <typeinfo>

template <class typ>
class Enemy_boat :public GameObject
{
protected:
	int x = rand() % 1175; //zeby nie wylecial za ekran
	int y = 240 + (rand() % 8) * 60; // 8 poziomow co 60 -> od 240 do 660
	ALLEGRO_BITMAP *b = al_load_bitmap("Ebomb.png");
	ALLEGRO_BITMAP *enemy1 = al_load_bitmap("enemy1.png");
	ALLEGRO_BITMAP *enemy2 = al_load_bitmap("enemy2.png");
	ALLEGRO_BITMAP *enemy3 = al_load_bitmap("enemy3.png");
	std::vector <typ> vec;
	std::string class_name = typeid(typ).name();
	int xe1, ye1;
	bool dir = 0;// 0->prawo, 1->lewo
	int zawroc; int dlugosc; int kalibruj;
	int hit = max;
	int hit_main = max;
public:
	Enemy_boat();
	Enemy_boat(int xx, int yy);
	void kalibracja();
	void movement();
	int get_hit();
	void set_hit();
	void collision(std::vector <wsp> bU, MainBoat *mb);
	void show();
	void add_bomb();
	bool movement_bomb();
	void show_bombs();
	int get_hit_main();
	void set_hit_main();
	void remove(std::vector <wsp> bU, MainBoat *mb);
	bool NextLevel();
	void reset();

};
#include "Enemy_boat.cpp"
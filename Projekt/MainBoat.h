#pragma once
#include "GameObject.h"
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h> 
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h> 
class MainBoat : public GameObject
{
private:
	int lifes = 3;
	ALLEGRO_BITMAP *boat = al_load_bitmap("main1.png");
	ALLEGRO_BITMAP *boat2 = al_load_bitmap("main2.png");
	bool dodano = false;
	int  move_level = 0;
	bool key[2] = { true,false }; //lewy, prawy
public:
	MainBoat();
	MainBoat(int xx, int yy);
	void set(int xx, int yy);
	void show();
	void show_Dead();
	void movement();
	void life();
	int getX();
	int getY();
	void add_life();
	int getLife();
	void utrata_zycia();
	bool GAMEOVER();
	void reset_NEW();
	void reset_bottle_and_move();
	void move(bool dir);

};

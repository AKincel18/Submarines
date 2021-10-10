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
	ALLEGRO_BITMAP *dead_boat = al_load_bitmap("main2.png");
	bool added = false;
	int  move_level = 0;
	bool key[2] = { true,false }; //left, right
public:
	MainBoat();
	MainBoat(int xx, int yy);
	void set(int xx, int yy);
	void show();
	void show_dead();
	void movement();
	void life();
	int getX();
	int getY();
	void add_life();
	int getLife();
	void lost_life();
	bool game_over();
	void reset_new();
	void reset_bottle_and_move();
	void move(bool dir);

};

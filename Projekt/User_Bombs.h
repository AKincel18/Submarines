#pragma once
#include "GameObject.h"
#include "MainBoat.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h> 
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h> 
#include <vector>
class User_Bombs :public GameObject
{
	ALLEGRO_BITMAP *bomb = al_load_bitmap("bomb.png");
	int first = 1375; //ustawienie 'zyc'		
public:
	User_Bombs();
	void add(MainBoat *mb);
	void movement();
	void show();
	void left();
	std::vector <wsp> getV();
	void usun(int ktory);
	void reset();
};

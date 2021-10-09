#pragma once
#include "GameObject.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Octopus : public GameObject
{
	ALLEGRO_BITMAP *octopus = al_load_bitmap("octopus.png");
	ALLEGRO_BITMAP *bottle = al_load_bitmap("bottle.png");
	bool wyrzucono = false;
	bool trafiony = false;
public:
	void show();
	void movement_bottle();
	void now();
	void trafiono();
	void show_bottle();
	void reset();
};

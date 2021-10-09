#pragma once
#include "MainBoat.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h> 
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h> 
class Menu
{
	ALLEGRO_TIMER *timerTIME = al_create_timer(1.0 / 1); //odmierzacz czasu
	ALLEGRO_EVENT_QUEUE *event_queue2 = al_create_event_queue();
	float SCREEN_W = 1400 //szerokosc ekranu
		, SCREEN_H = 800; //wysokosc
	ALLEGRO_FONT *font = al_load_font("4mini.ttf", 50, 0);
	ALLEGRO_EVENT ev3;
public:
	void dead_but_play(MainBoat *mb);
	void win(MainBoat *mb);
	bool new_game();
	void game_over(MainBoat *mb);
};

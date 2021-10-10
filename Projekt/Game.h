#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h> 
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h> 
class Game
{
	bool key[2] = { false,false }; //left, right
	float SCREEN_W = 1400 //screen width
		, SCREEN_H = 800; //screen height 
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	ALLEGRO_EVENT_QUEUE *event_queue2 = al_create_event_queue();
	ALLEGRO_DISPLAY* display = al_create_display(SCREEN_W, SCREEN_H);
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / 10);
	ALLEGRO_TIMER *timerE1 = al_create_timer(1.0 / 7); //movement for enemy1
	ALLEGRO_TIMER *timerE2 = al_create_timer(1.0 / 15); //movement for enemy2
	ALLEGRO_TIMER *timerE3 = al_create_timer(1.0 / 20); //movement for enemy3
	ALLEGRO_TIMER *timerUB = al_create_timer(1.0 / 10); //movement for enemy3
	ALLEGRO_TIMER *timerEB1 = al_create_timer(1.0 / 0.5); //movement for enemy1 bombs
	ALLEGRO_TIMER *timerEB2 = al_create_timer(1.0 / 1); //movement for enemy2 bombs
	ALLEGRO_TIMER *timerEB3 = al_create_timer(1.0 / 0.5); //movement for enemy3 bombs
	ALLEGRO_TIMER *timerBottle = al_create_timer(1.0 / 0.1); //bottle ejection
	ALLEGRO_FONT *font_points = al_load_font("4mini.ttf", 20, 0);
	int move_level = 1;
	bool doexit = false;
	bool redraw = false;
	bool is_hit = false;
	bool is_menu = true;
	bool is_win = false;
	bool is_lose = false;
	bool is_reset = false;

public:
	Game();
	void register1();
	void timer1();
	void destroy1();
	void create1();
	void new_game();

};

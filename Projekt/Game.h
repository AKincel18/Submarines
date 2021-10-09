#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h> 
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h> 
class Game
{
bool key[2] = { false,false }; //lewy, prawy
float SCREEN_W = 1400 //szerokosc ekranu
, SCREEN_H = 800; //wysokosc
ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
ALLEGRO_EVENT_QUEUE *event_queue2 = al_create_event_queue();
ALLEGRO_DISPLAY* display = al_create_display(SCREEN_W, SCREEN_H);
ALLEGRO_TIMER *timer = al_create_timer(1.0 / 10);
ALLEGRO_TIMER *timerE1 = al_create_timer(1.0 / 7); //poruszanie sie enemy1
ALLEGRO_TIMER *timerE2 = al_create_timer(1.0 / 15); //poruszanie sie enemy2
ALLEGRO_TIMER *timerE3 = al_create_timer(1.0 / 20); //poruszanie sie enemy3
ALLEGRO_TIMER *timerUB = al_create_timer(1.0 / 10); //poruszanie sie enemy3
ALLEGRO_TIMER *timerEB1 = al_create_timer(1.0 / 0.5); //poruszanie sie enemy1 bombs
ALLEGRO_TIMER *timerEB2 = al_create_timer(1.0 / 1); //poruszanie sie enemy2 bombs
ALLEGRO_TIMER *timerEB3 = al_create_timer(1.0 / 0.5); //poruszanie sie enemy3 bombs
ALLEGRO_TIMER *timerBottle = al_create_timer(1.0 / 0.1); //wystrzal butelki
ALLEGRO_FONT *font_points = al_load_font("4mini.ttf", 20, 0);
int move_level = 1; // level wcisniec
bool doexit = false;
bool redraw = false;
bool trafionyO = false;
bool menu = true;
bool win = false;
bool lose = false;
bool reset = false;

public:
	void register1();
	void timer1();
	void destroy1();
	void create1();
	void NEWGAME();

};

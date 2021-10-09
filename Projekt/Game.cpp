#include "Game.h"
#include "MainBoat.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Menu.h"
#include "User_Bombs.h"
#include "Octopus.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h> 
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h> 
#include<string>
#include <iostream>
void Game::register1()
{
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_timer_event_source(timerE1));
	al_register_event_source(event_queue, al_get_timer_event_source(timerE2));
	al_register_event_source(event_queue, al_get_timer_event_source(timerE3));
	al_register_event_source(event_queue, al_get_timer_event_source(timerUB));
	al_register_event_source(event_queue, al_get_timer_event_source(timerEB1));
	al_register_event_source(event_queue, al_get_timer_event_source(timerEB2));
	al_register_event_source(event_queue, al_get_timer_event_source(timerEB3));
	al_register_event_source(event_queue, al_get_timer_event_source(timerBottle));
	//al_register_event_source(event_queue2, al_get_timer_event_source(timerTIME));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue2, al_get_keyboard_event_source());

}
void Game::timer1()
{
	al_start_timer(timer);
	al_start_timer(timerE1);
	al_start_timer(timerE2);
	al_start_timer(timerE3);
	al_start_timer(timerUB);
	al_start_timer(timerEB1);
	al_start_timer(timerEB2);
	al_start_timer(timerEB3);
	al_start_timer(timerBottle);
}
void Game::destroy1()
{
	al_destroy_timer(timer);
	al_destroy_timer(timerE1);
	al_destroy_timer(timerE2);
	al_destroy_timer(timerE3);
	al_destroy_timer(timerUB);
	al_destroy_timer(timerEB1);
	al_destroy_timer(timerEB2);
	al_destroy_timer(timerEB3);
	al_destroy_timer(timerBottle);
}
void Game::create1()
{
	timer = al_create_timer(1.0 / 10);
	timerE1 = al_create_timer(1.0 / 7); //poruszanie sie enemy1
	timerE2 = al_create_timer(1.0 / 15); //poruszanie sie enemy2
	timerE3 = al_create_timer(1.0 / 20); //poruszanie sie enemy3
	timerUB = al_create_timer(1.0 / 10); //poruszanie sie user bombs
	timerEB1 = al_create_timer(1.0 / 0.5); //poruszanie sie enemy1 bombs
	timerEB2 = al_create_timer(1.0 / 1); //poruszanie sie enemy2 bombs
	timerEB3 = al_create_timer(1.0 / 1.5); //poruszanie sie enemy3 bombs
	timerBottle = al_create_timer(1.0 / 0.1); //poruszanie sie enemy3 bombs 0.1 co 10 sekun
}
void Game::NEWGAME()
{
	
	al_set_window_title(display, "SUBMARINES");
	al_set_target_bitmap(al_get_backbuffer(display));
	al_install_keyboard();
	register1();
	timer1();
	MainBoat *mb = new MainBoat(650, 100);
	User_Bombs *b = new User_Bombs();
	Enemy1 *eb = new Enemy1(); eb->kalibracja();
	Enemy2 *eb2 = new Enemy2(); eb2->kalibracja();
	Enemy3 *eb3 = new Enemy3();  eb3->kalibracja();
	Octopus *o = new Octopus;
	Menu m;
	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		while (menu)
		{
			reset = true;
			ALLEGRO_EVENT ev3;
			al_wait_for_event(event_queue, &ev3);

			if (lose && !(mb->GAMEOVER())) // 1. utrata zycia ale gramy dalej
			{
				m.dead_but_play(mb);
				destroy1();
				create1();
				register1();
				timer1();
				menu = false;
				lose = false;
				win = false;
				mb->reset_bottle_and_move();
			}
			else if (win) //wygrana
			{
				m.win(mb);
				menu = true;
				lose = false;
				win = false;
				mb->reset_NEW();
			}
			else if (!win && !lose) //2. poczatek gry (zupelnie nowa gra z 3 zyciami)
			{
				switch (m.new_game())
				{
				case 0:
					//timer1();
					menu = false;
					break;
				case 1:
					doexit = true;
					menu = false;
					break;
				}
				destroy1();
				create1();
				register1();
				timer1();
				mb->reset_NEW();
			}
			else if (mb->GAMEOVER()) //3. KONIEC GRY
			{
				m.game_over(mb);
				menu = true;
				lose = false;
				win = false;
				mb->reset_NEW();
				destroy1();
				create1();
				register1();
				timer1();
			}

		}

		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			if (ev.timer.source == timer)
			{
				mb->movement();
				redraw = true;
			}
			if (ev.timer.source == timerE1)
			{

				o->movement_bottle();
				//b->usun(eb->movement(b->getV(), mb));
				//eb->movement();
				eb->collision(b->getV(), mb);
				b->usun(eb->get_hit());
				eb->movement_bomb();
				if (eb->Dead(mb->getX()))
				{
					lose = true;
				}

				redraw = true;
			}
			if (ev.timer.source == timerE2)
			{
				eb2->movement_bomb();
				//eb2->movement();
				eb2->collision(b->getV(), mb);
				b->usun(eb2->get_hit());
				if (eb2->Dead(mb->getX()))
				{
					lose = true;
				}

				redraw = true;
			}
			if (ev.timer.source == timerE3)
			{
				eb3->movement_bomb();
				//eb3->movement();
				eb3->collision(b->getV(), mb);
				b->usun(eb3->get_hit());
				if (eb3->Dead(mb->getX()))
				{

					lose = true;
				}
				redraw = true;
			}
			if (ev.timer.source == timerUB)
			{
				b->movement();
				redraw = true;
			}
			if (ev.timer.source == timerEB1)
			{
				eb->add_bomb();
			}
			if (ev.timer.source == timerEB2)
			{
				eb2->add_bomb();
			}
			if (ev.timer.source == timerEB3)
			{
				eb3->add_bomb();
			}
			if (ev.timer.source == timerBottle) //wyrzut butelki
			{
				o->now();

			}

		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{

			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_LEFT:
				mb->move(0);
				break;
			case ALLEGRO_KEY_RIGHT:
				mb->move(1);
				break;
			case ALLEGRO_KEY_DOWN:
				//tworzenie bomb
				b->add(mb);
				break;
			case ALLEGRO_KEY_ESCAPE:
				menu = true;
				break;


			}
		}

		if (redraw && !doexit)
		{
			if (reset)
			{

				mb->set(650, 100);
				b->reset();
				trafionyO = false;
				o->reset();
				eb->reset();
				eb2->reset();
				eb3->reset();
				eb->create();
				eb2->create();
				eb3->create();
				reset = false;
			}

			//	al_clear_to_color(al_map_rgb(0, 0, 255));	//tlo reszta
			al_draw_filled_rectangle(0, 0, 1400, 143, al_map_rgb(153, 217, 234));	//tlo horyzont
			al_draw_filled_rectangle(0, 143, 1400, 700, al_map_rgb(0, 0, 255));	//morze
			al_draw_filled_rectangle(0, 700, 1400, 800, al_map_rgb(255, 255, 100));	//tlo piasek
			redraw = false;
			if (!lose)
				mb->show();
			else
				mb->show_Dead();


			b->left();
			b->show();


			if (o->NewLife(mb->getX()))
			{
				mb->add_life();
			}


			mb->life();
			//obluga bomb

			eb->remove(b->getV(), mb);
			eb2->remove(b->getV(), mb);
			eb3->remove(b->getV(), mb);
			b->usun(eb->get_hit_main());
			b->usun(eb2->get_hit_main());
			b->usun(eb3->get_hit_main());

			eb->show_bombs();
			eb2->show_bombs();
			eb3->show_bombs();

			if (trafionyO == false)
			{
				if (b->CheckCollision() == false) //czy osmiornica dostala bombom
					o->show();
				else
				{
					trafionyO = true;
					o->trafiono();
				}
			}

			o->show_bottle();

			eb->show();
			eb2->show();
			eb3->show();
			al_draw_textf(font_points, al_map_rgb(255, 0, 0), 0, 80, 0, "Liczba punktow: %i", mb->getPOINTS());


			al_flip_display();


			if (eb->NextLevel() && eb2->NextLevel() && eb3->NextLevel()) //WYGRANA
			{
				al_rest(2);
				win = true;
				menu = true;
			}

			if (lose) //NASZ OKRET DOSTAL
			{

				mb->utrata_zycia();
				al_rest(2);
				menu = true;
				lose = true;
			}


		}

	}

}
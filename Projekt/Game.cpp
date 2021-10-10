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
Game::Game()
{
	this->new_game();
}
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
	//al_register_event_source(event_queue2, al_get_timer_event_source(timer));
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
	//elements movement
	timerE1 = al_create_timer(1.0 / 7);
	timerE2 = al_create_timer(1.0 / 15);
	timerE3 = al_create_timer(1.0 / 20);
	timerUB = al_create_timer(1.0 / 10);
	timerEB1 = al_create_timer(1.0 / 0.5);
	timerEB2 = al_create_timer(1.0 / 1);
	timerEB3 = al_create_timer(1.0 / 1.5);
	timerBottle = al_create_timer(1.0 / 0.1);
}
void Game::new_game()
{
	al_set_window_title(display, "SUBMARINES");
	al_set_target_bitmap(al_get_backbuffer(display));
	al_install_keyboard();
	register1();
	timer1();
	MainBoat *main_boat = new MainBoat(650, 100);
	User_Bombs *user_bomb = new User_Bombs();
	Enemy1 *enemy1 = new Enemy1(); enemy1->calibrate();
	Enemy2 *enemy2 = new Enemy2(); enemy2->calibrate();
	Enemy3 *enemy3 = new Enemy3();  enemy3->calibrate();
	Octopus *octopus = new Octopus;
	Menu menu;
	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		while (is_menu)
		{
			is_reset = true;
			ALLEGRO_EVENT ev3;
			al_wait_for_event(event_queue, &ev3);

			if (is_lose && !(main_boat->game_over())) // 1. lost life but still play
			{
				menu.dead_but_play(main_boat);
				destroy1();
				create1();
				register1();
				timer1();
				is_menu = false;
				is_lose = false;
				is_win = false;
				main_boat->reset_bottle_and_move();
			}
			else if (is_win) //win
			{
				menu.win(main_boat);
				is_menu = true;
				is_lose = false;
				is_win = false;
				main_boat->reset_new();
			}
			else if (!is_win && !is_lose) //2. new game (with 3 lifes)
			{
				switch (menu.new_game())
				{
				case 0:
					is_menu = false;
					break;
				case 1:
					doexit = true;
					is_menu = false;
					break;
				}
				destroy1();
				create1();
				register1();
				timer1();
				main_boat->reset_new();
			}
			else if (main_boat->game_over()) //3. end of the game
			{
				menu.game_over(main_boat);
				is_menu = true;
				is_lose = false;
				is_win = false;
				main_boat->reset_new();
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
				main_boat->movement();
				redraw = true;
			}
			if (ev.timer.source == timerE1)
			{
				octopus->movement_bottle();
				enemy1->collision(user_bomb->getV(), main_boat);
				user_bomb->remove(enemy1->get_hit());
				enemy1->movement_bomb();
				if (enemy1->is_dead(main_boat->getX()))
				{
					is_lose = true;
				}

				redraw = true;
			}
			if (ev.timer.source == timerE2)
			{
				enemy2->movement_bomb();
				enemy2->collision(user_bomb->getV(), main_boat);
				user_bomb->remove(enemy2->get_hit());
				if (enemy2->is_dead(main_boat->getX()))
				{
					is_lose = true;
				}

				redraw = true;
			}
			if (ev.timer.source == timerE3)
			{
				enemy3->movement_bomb();
				enemy3->collision(user_bomb->getV(), main_boat);
				user_bomb->remove(enemy3->get_hit());
				if (enemy3->is_dead(main_boat->getX()))
				{
					is_lose = true;
				}
				redraw = true;
			}
			if (ev.timer.source == timerUB)
			{
				user_bomb->movement();
				redraw = true;
			}
			if (ev.timer.source == timerEB1)
			{
				enemy1->add_bomb();
			}
			if (ev.timer.source == timerEB2)
			{
				enemy2->add_bomb();
			}
			if (ev.timer.source == timerEB3)
			{
				enemy3->add_bomb();
			}
			if (ev.timer.source == timerBottle)
			{
				octopus->throw_away_bottle();

			}

		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{

			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_LEFT:
				main_boat->move(0);
				break;
			case ALLEGRO_KEY_RIGHT:
				main_boat->move(1);
				break;
			case ALLEGRO_KEY_DOWN:
				//create bomb
				user_bomb->add(main_boat);
				break;
			case ALLEGRO_KEY_ESCAPE:
				is_menu = true;
				break;
			}
		}

		if (redraw && !doexit)
		{
			if (is_reset)
			{
				main_boat->set(650, 100);
				user_bomb->reset();
				is_hit = false;
				octopus->reset();
				enemy1->reset();
				enemy2->reset();
				enemy3->reset();
				enemy1->create();
				enemy2->create();
				enemy3->create();
				is_reset = false;
			}

			al_draw_filled_rectangle(0, 0, 1400, 143, al_map_rgb(153, 217, 234));	//horizon background
			al_draw_filled_rectangle(0, 143, 1400, 700, al_map_rgb(0, 0, 255));	//sea
			al_draw_filled_rectangle(0, 700, 1400, 800, al_map_rgb(255, 255, 100));	//sand background
			redraw = false;
			if (!is_lose)
				main_boat->show();
			else
				main_boat->show_dead();

			user_bomb->left();
			user_bomb->show();
			if (octopus->new_life(main_boat->getX()))
			{
				main_boat->add_life();
			}

			main_boat->life();

			//bomb handling
			enemy1->remove(user_bomb->getV(), main_boat);
			enemy2->remove(user_bomb->getV(), main_boat);
			enemy3->remove(user_bomb->getV(), main_boat);
			user_bomb->remove(enemy1->get_hit_main());
			user_bomb->remove(enemy2->get_hit_main());
			user_bomb->remove(enemy3->get_hit_main());

			enemy1->show_bombs();
			enemy2->show_bombs();
			enemy3->show_bombs();

			if (is_hit == false)
			{
				if (user_bomb->check_collision() == false)
					octopus->show();
				else
				{
					is_hit = true;
					octopus->hit_optocus();
				}
			}

			octopus->show_bottle();

			enemy1->show();
			enemy2->show();
			enemy3->show();
			al_draw_textf(font_points, al_map_rgb(255, 0, 0), 0, 80, 0, "Number of points: %i", main_boat->get_points());


			al_flip_display();


			if (enemy1->next_level() && enemy2->next_level() && enemy3->next_level()) //win
			{
				al_rest(2);
				is_win = true;
				is_menu = true;
			}

			if (is_lose) //main boat dead
			{

				main_boat->lost_life();
				al_rest(2);
				is_menu = true;
				is_lose = true;
			}


		}

	}

}
#include "Menu.h"

void Menu::dead_but_play(MainBoat *mb)
{

	al_register_event_source(event_queue2, al_get_timer_event_source(timer));
	al_start_timer(timer);
	int i = 5; //5 seconds to start the game

	while (i != -1)
	{
		//al_start_timer(timer);
		ALLEGRO_EVENT ev2;
		al_wait_for_event(event_queue2, &ev2);
		if (ev2.type == ALLEGRO_EVENT_TIMER && ev2.timer.source == timer)
		{
			al_clear_to_color(al_map_rgb(0, 0, 255));
			al_draw_textf(font, al_map_rgb(255, 255, 0), SCREEN_W / 2, SCREEN_H / 2 - 30, ALLEGRO_ALIGN_CENTRE, "NUMBER OF LIVES: %i", mb->getLife());
			al_draw_textf(font, al_map_rgb(255, 255, 0), SCREEN_W / 2, SCREEN_H / 2 + 30, ALLEGRO_ALIGN_CENTRE, "TIME TO START: %i", i);
			al_flip_display();
			i--;
		}
	}
	al_stop_timer(timer);
}

void Menu::win(MainBoat *mb)
{
	al_clear_to_color(al_map_rgb(0, 0, 255));
	al_draw_text(font, al_map_rgb(255, 255, 0), SCREEN_W / 2, SCREEN_H / 2 - 30, ALLEGRO_ALIGN_CENTRE, "YOU WIN ");
	al_draw_textf(font, al_map_rgb(255, 255, 0), SCREEN_W / 2, SCREEN_H / 2 + 30, ALLEGRO_ALIGN_CENTRE, "RESULT: %i", mb->get_points());
	al_flip_display();
	al_clear_to_color(al_map_rgb(0, 0, 255));
	al_rest(3);

}

bool Menu::new_game()
{
	event_queue2 = al_create_event_queue();
	al_register_event_source(event_queue2, al_get_keyboard_event_source());
	do
	{
		al_clear_to_color(al_map_rgb(0, 0, 255));
		al_draw_text(font, al_map_rgb(255, 255, 0), SCREEN_W / 2, SCREEN_H / 2 - 30, ALLEGRO_ALIGN_CENTRE, "PRESS 'ENTER' TO START THE GAME!");
		al_draw_text(font, al_map_rgb(255, 255, 0), SCREEN_W / 2, SCREEN_H / 2 + 30, ALLEGRO_ALIGN_CENTRE, "PRESS 'ESC' TO EXIT THE GAME!");
		al_flip_display();
		al_wait_for_event(event_queue2, &ev3);

		if (ev3.type == ALLEGRO_EVENT_KEY_DOWN)
		{

			if (ev3.keyboard.keycode == ALLEGRO_KEY_ENTER)
			{
				return 0;
			}
			if (ev3.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
			{
				return 1;
			}
		}
	} while (ev3.keyboard.keycode != ALLEGRO_KEY_ENTER || ev3.keyboard.keycode != ALLEGRO_KEY_ESCAPE);

}

void Menu::game_over(MainBoat *mb)
{
	al_clear_to_color(al_map_rgb(0, 0, 255));
	al_draw_text(font, al_map_rgb(255, 255, 0), SCREEN_W / 2, SCREEN_H / 2 - 60, ALLEGRO_ALIGN_CENTRE, "GAME OVER!");
	al_draw_textf(font, al_map_rgb(255, 255, 0), SCREEN_W / 2, SCREEN_H / 2, ALLEGRO_ALIGN_CENTRE, "RESULT: %i", mb->get_points());
	al_flip_display();
	al_rest(2);
}
#include "Menu.h"

void Menu::dead_but_play(MainBoat *mb)
{

	al_register_event_source(event_queue2, al_get_timer_event_source(timerTIME));
	al_start_timer(timerTIME);
	int i = 5; //5 sekund do rozpoczecia gry -> 5 4 3 2 1 GRAMY!

	while (i != -1)
	{
		//al_start_timer(timerTIME);
		ALLEGRO_EVENT ev2;
		al_wait_for_event(event_queue2, &ev2);
		if (ev2.type == ALLEGRO_EVENT_TIMER && ev2.timer.source == timerTIME)
		{

			//cout << "weszlo" << endl;

			al_clear_to_color(al_map_rgb(0, 0, 255));
			al_draw_textf(font, al_map_rgb(255, 255, 0), SCREEN_W / 2, SCREEN_H / 2 - 30, ALLEGRO_ALIGN_CENTRE, "ILOSC ZYC: %i", mb->getLife());
			al_draw_textf(font, al_map_rgb(255, 255, 0), SCREEN_W / 2, SCREEN_H / 2 + 30, ALLEGRO_ALIGN_CENTRE, "SEKUND DO ROZPOCZECIA: %i", i);
			al_flip_display();
			i--;

		}
	}
	al_stop_timer(timerTIME);
}
void Menu::win(MainBoat *mb)
{
	al_clear_to_color(al_map_rgb(0, 0, 255));
	al_draw_text(font, al_map_rgb(255, 255, 0), SCREEN_W / 2, SCREEN_H / 2 - 30, ALLEGRO_ALIGN_CENTRE, "WYGRANA ");
	al_draw_textf(font, al_map_rgb(255, 255, 0), SCREEN_W / 2, SCREEN_H / 2 + 30, ALLEGRO_ALIGN_CENTRE, "WYNIK: %i", mb->getPOINTS());
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
		al_draw_text(font, al_map_rgb(255, 255, 0), SCREEN_W / 2, SCREEN_H / 2 - 30, ALLEGRO_ALIGN_CENTRE, "KILKNIJ ENTER ABY ZACZAC GRE!");
		al_draw_text(font, al_map_rgb(255, 255, 0), SCREEN_W / 2, SCREEN_H / 2 + 30, ALLEGRO_ALIGN_CENTRE, "KILKNIJ ESC ABY WYLACZYC GRE!");
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
	al_draw_text(font, al_map_rgb(255, 255, 0), SCREEN_W / 2, SCREEN_H / 2 - 60, ALLEGRO_ALIGN_CENTRE, "KONIEC GRY ");
	al_draw_textf(font, al_map_rgb(255, 255, 0), SCREEN_W / 2, SCREEN_H / 2, ALLEGRO_ALIGN_CENTRE, "WYNIK: %i", mb->getPOINTS());
	//al_draw_text(font2, al_map_rgb(255, 255, 0), SCREEN_W / 2, SCREEN_H / 2 + 60, ALLEGRO_ALIGN_CENTRE, "NACISNIJ DOWOLNY KLAWISZ ABY WROCIC DO MENU");
	al_flip_display();
	//al_clear_to_color(al_map_rgb(0, 0, 0));
	al_rest(2);

}
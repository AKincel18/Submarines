#include "Octopus.h"

void Octopus::show()
{
	al_draw_tinted_bitmap(octopus, al_map_rgb(255, 255, 100), xO, yO, 0);
}
void Octopus::movement_bottle()
{
	if (is_throw_away_bottle)
		yBottle -= 10;
}
void Octopus::throw_away_bottle()
{
	if (is_hit_octopus == false)
		is_throw_away_bottle = true;
}
void Octopus::hit_optocus()
{
	is_hit_octopus = true;
}
void Octopus::show_bottle()
{
	if (is_hit_octopus == false || is_throw_away_bottle == true)
	{
		if (yBottle >= 143)
		{
			if (yBottle >= 700)
				al_draw_tinted_bitmap(bottle, al_map_rgb(255, 255, 100), xO, yBottle, 0);
			else
				al_draw_tinted_bitmap(bottle, al_map_rgb(0, 0, 255), xO, yBottle, 0);
		}
	}
}
void Octopus::reset()
{
	is_throw_away_bottle = false;
	is_hit_octopus = false;
	xO = 500, yO = 710;
	yBottle = yO;
}
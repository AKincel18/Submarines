#include "Octopus.h"

void Octopus::show()
{
	al_draw_tinted_bitmap(octopus, al_map_rgb(255, 255, 100), xO, yO, 0);
}
void Octopus::movement_bottle()
{
	if (wyrzucono)
		yBottle -= 10;
}
void Octopus::now()
{
	if (trafiony == false)
		wyrzucono = true;
}
void Octopus::trafiono()
{
	trafiony = true;
}
void Octopus::show_bottle()
{
	if (trafiony == false || wyrzucono == true)
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
	wyrzucono = false;
	trafiony = false;
	xO = 500,
		yO = 710;			   //zeby na piasku byl
	yBottle = yO;
}
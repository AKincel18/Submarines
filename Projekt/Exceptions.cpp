#include "Exceptions.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h> 
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h> 
	bool Exceptions::check()
	{
		try
		{
			al_init();
			al_init_font_addon();
			al_init_ttf_addon();
			al_init_primitives_addon();
			al_init_image_addon();
		}
		catch (...)
		{
			return false;
		}
		return true;
	}

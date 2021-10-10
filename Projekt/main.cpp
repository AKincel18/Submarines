#include <iostream>
#include <string>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h> 
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h> 
#include <cstdlib>
#include <vector>
#include <ctime>
#include <typeinfo>
#include "Exceptions.h"
#include "Game.h"

using namespace std;
int main()
{
	srand(time(NULL));
	Exceptions e;
	if (e.check_init_allegro() == false)
	{
		cout << "ALLEGRO ERROR" << endl;
		exit(EXIT_FAILURE);
	}	
	Game g; //start the game
	return 0;	
}
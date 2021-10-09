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
	cout << "WCHODZI" << endl;
	Exceptions e;
	if (e.check() == false)
	{
		cout << "ALLEGRO ERROR" << endl;
		exit(EXIT_FAILURE);
	}
	
	Game g;
	
	g.NEWGAME();
	return 0;


	
}
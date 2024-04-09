#include <iostream> 
#include <SFML/Graphics.hpp> 
#include "Headers/Unit.h"
#include "Headers/Game.h"
#include "Headers/Character.h"
#include "Headers/Graphics.h"

int main()
{
	Player* p = new Player();
	Unit* u = new Unit();
	Wizard* w = new Wizard();
	//cout << p->getData().name << endl;

	Mob* m = new Mob("slime", 3, 200, 16, 8, 10);
	Battle bat(p,m);

	return 0;
}

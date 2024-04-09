#include <iostream> 
#include <SFML/Graphics.hpp> 
#include "Headers/Unit.h"
#include "Headers/Game.h"
#include "Headers/Character.h"

int main()
{
	Player* p = new Player();
	Unit* u = new Unit();
	Wizard* w = new Wizard();
	cout << p->getData().name << endl;

	Mob* m = new Mob("slime",5,20,8,8,8);
	Battle bat(p,m);

}

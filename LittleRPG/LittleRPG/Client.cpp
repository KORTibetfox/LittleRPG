#include <iostream> 
#include <SFML/Graphics.hpp> 
#include "Headers/Unit.h"
#include "Headers/Character.h"
#include "Headers/Game.h"

int main()
{
	int a;
	Player* p = new Player();
	cout << p->getData()->name << endl;
	//Mob* m = new Mob("slime",5,20,8,8,8);
	//Battle bat(p,m);
	cin >> a;
	cout << a << endl;
}

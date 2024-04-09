#pragma once

#include <iostream>
#include <random>
#include "Unit.h"
#include "Graphics.h"

//temp library
#include <conio.h>
#define MAX(a,b) a > b ? a : b

using namespace std;

//Game Manager : Singleton Pattern
class Game
{
private:
	static Game* instance;

public:
	Game()
	{
		this->getInstance();
	}

	Game* getInstance()
	{
		if (this->instance == nullptr)
		{
			instance = new Game();
		}
		return instance;
	}
	~Game() { delete instance; }
};

class Random
{
public:
	static int getRandomNumber(int range)
	{
		int r = 0;
		random_device rd;
		mt19937 gen(rd());

		uniform_int_distribution<int> dis(0, range);

		return dis(rd);
	}
};

class Dice
{
public:

	static int rolltheDice(int count, int range)
	{
		int sum = 0;
		for (int i = 0; i < count; i++) 		
			sum += Random::getRandomNumber(range);
		return sum;
	}

	static int rolltheDice(int range)
	{
		return Random::getRandomNumber(range);
	}
};

class Interface
{
public:
	static void WAIT()
	{
		char c = _getch();
	}

	static void diceMessage()
	{
		cout << "Try Roll The Dice!!" <<endl;
	}
};


class Graphics {
public:

	static void showBattleScene(Player* player, Mob* mob)
	{
		printf("[ Player ] hp : %d  / %d\n", player->getData().cur_hp, player->getData().max_hp);
		printf("[   Mob  ] hp : %d  / %d\n", mob->getData().cur_hp, mob->getData().max_hp);
	}
};

class Battle
{
private:

	void setFirstAttacker(Player* player, Mob* mob) // Choice Who first attack
	{
		Graphics::showBattleScene(player, mob);
		Interface::diceMessage();
		Interface::WAIT();

		cout << "* select first attacker" <<endl;

		int player_result = Dice::rolltheDice(20);
		int mob_result = Dice::rolltheDice(20);

		cout << "Your dice : " << player_result << " And Mob dice : " << mob_result << endl;

		if (player_result >= mob_result) {
			cout << "Your Turn!" << endl;
			this->executeAttack(player, mob, player, mob);
		}
		else if (player_result < mob_result) {

			cout << "Mob Turn!" << endl;
			this->executeAttack(mob, player, player, mob);
		}
	}

	bool isDead(Unit* unit)
	{
		if (unit->getData().cur_hp <= 0)
		{
		cout << "Unit is Dead" << endl;
		return true;
		}
		return false;
	}

	void executeAttack(Unit* attacker, Unit* defender, Player* player, Mob* mob)
	{
		Graphics::showBattleScene(player, mob);
		Interface::diceMessage();
		Interface::WAIT();

		int attack_damage = Dice::rolltheDice(2, 20);
		int defense_chance = Dice::rolltheDice(20);
		cout << "Damage : " <<attack_damage << endl;

		if (attack_damage > defense_chance) {
			defender->setCurHp(attack_damage);
			if(this->isDead(defender)) return;
		}
		
		cout << "Atk HP : " << attacker->getData().cur_hp << "\tDef's HP" << defender->getData().cur_hp << endl;
		this->exchangeTurn(attacker, defender, player, mob);
	}

	void exchangeTurn(Unit* attacker, Unit* defender, Player* player, Mob* mob) // You are fool if you can't understand this
	{

		cout << "change" << endl;
		Unit* temp;
		temp = attacker;
		attacker = defender;
		defender = temp;

		this->executeAttack(attacker, defender, player, mob);
	}

public:

	Battle(Player* player, Mob* mob)
	{
		this->setFirstAttacker(player, mob);
	}
};






#pragma once

#include <iostream>
#include <random>
#include "Headers/Unit.h"

//temp library
#include <conio.h>
#define MAX(a,b) a > b ? a : b

using namespace std;

//Game Manager : Singleton ?„ë¡œê·¸ëž¨?ì„œ ???˜ë‚˜ë§?ì¡´ìž¬
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
		cout << "?„ë¬´ ?¤ë‚˜ ?ŒëŸ¬ ì£¼ì‚¬?„ë? ?˜ì??¸ìš”." <<endl;
	}
};

class Battle
{
private:

	void setFirstAttacker(Unit* player, Unit* mob) // ? ê³µê¶??•í•˜ê¸?
	{
		Interface::diceMessage();
		Interface::WAIT();

		cout << "* select first attacker" <<endl;

		int player_result = Dice::rolltheDice(20);
		int mob_result = Dice::rolltheDice(20);

		cout << "Your dice : " << player_result << " Mob dice : " << mob_result << endl;

		if (player_result >= mob_result) {
			cout << "Your Turn!" << endl;
			this->executeAttack(player, mob);
		}
		else if (player_result < mob_result) {

			cout << "Mob Turn!" << endl;
			this->executeAttack(mob, player);
		}
	}

	bool isDead(Unit* unit)
	{
		if (unit->getData()->cur_hp <= 0)
		{
		cout << "Unit is Dead" << endl;
		return true;
		}
		return false;
	}

	void executeAttack(Unit* attacker, Unit* defender) // ?°ë?ì§€ë¥?ì£¼ëŠ” ê³¼ì •
	{
		// ê³µê²© ?°ë?ì§€ ?¤ì •
		Interface::diceMessage();
		Interface::WAIT();

		int attack_damage = Dice::rolltheDice(2, 20);
		int defense_chance = Dice::rolltheDice(20);
		cout << "Damage : " <<attack_damage << endl;

		// ê³µê²© (ì²´ë ¥ ê°ì†Œ)
		if (attack_damage > defense_chance) {
			defender->getData()->cur_hp -= attack_damage;
			//?¬ë§??ë°œìƒ ??ë°°í? ì¢…ë£Œ
			if(this->isDead(defender)) return;
		}
		// ?Œí”¼
		
		cout << "Atk HP : " << attacker->getData()->cur_hp << "Def HP" << defender->getData()->cur_hp << endl;
		//???˜ê¸°ê¸?
		this->exchangeTurn(attacker, defender);
	}

	void exchangeTurn(Unit* attacker, Unit* defender) { // ?´ë„˜ê¸°ê¸°

		cout << "change" << endl;
		Unit* temp;
		temp = attacker;
		attacker = defender;
		defender = temp;

		this->executeAttack(attacker, defender);
	}

public:

	Battle(Unit* player, Unit* mob)
	{
		cout << "Battle Start !" <<endl;
		this->setFirstAttacker(player,mob);
	}
};







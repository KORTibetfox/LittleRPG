#pragma once

#include <iostream>
#include <random>
#include "Headers/Unit.h"

//temp library
#include <conio.h>
#define MAX(a,b) a > b ? a : b

using namespace std;

//Game Manager : Singleton ?�로그램?�서 ???�나�?존재
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
		cout << "?�무 ?�나 ?�러 주사?��? ?��??�요." <<endl;
	}
};

class Battle
{
private:

	void setFirstAttacker(Unit* player, Unit* mob) // ?�공�??�하�?
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

	void executeAttack(Unit* attacker, Unit* defender) // ?��?지�?주는 과정
	{
		// 공격 ?��?지 ?�정
		Interface::diceMessage();
		Interface::WAIT();

		int attack_damage = Dice::rolltheDice(2, 20);
		int defense_chance = Dice::rolltheDice(20);
		cout << "Damage : " <<attack_damage << endl;

		// 공격 (체력 감소)
		if (attack_damage > defense_chance) {
			defender->getData()->cur_hp -= attack_damage;
			//?�망??발생 ??배�? 종료
			if(this->isDead(defender)) return;
		}
		// ?�피
		
		cout << "Atk HP : " << attacker->getData()->cur_hp << "Def HP" << defender->getData()->cur_hp << endl;
		//???�기�?
		this->exchangeTurn(attacker, defender);
	}

	void exchangeTurn(Unit* attacker, Unit* defender) { // ?�넘기기

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







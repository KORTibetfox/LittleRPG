#pragma once

#include <iostream>
#include <random>
#include "Headers/Unit.h"

//temp library
#include <conio.h>
#define MAX(a,b) a > b ? a : b

using namespace std;

//Game Manager : Singleton 프로그램에서 단 하나만 존재
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
		cout << "아무 키나 눌러 주사위를 던지세요." <<endl;
	}
};

class Battle
{
private:

	void setFirstAttacker(Unit* player, Unit* mob) // 선공권 정하기
	{
		Interface::diceMessage();
		Interface::WAIT();

		cout << "왜안떠!" <<endl;

		int player_result = Dice::rolltheDice(20);
		int mob_result = Dice::rolltheDice(20);

		cout << "당신의 수 : " << player_result << " 몹 수 : " << mob_result << endl;

		if (player_result >= mob_result) {
			cout << "당신이 먼저 공격합니다!" << endl;
			this->executeAttack(player, mob);
		}
		else if (player_result < mob_result) {

			cout << "상대가 먼저 공격합니다!" << endl;
			this->executeAttack(mob, player);
		}
	}

	bool isDead(Unit* unit)
	{
		if (unit->getData()->cur_hp <= 0)
		{
		cout << "유닛이 사망했습니다." << endl;
		return true;
		}
		return false;
	}

	void executeAttack(Unit* attacker, Unit* defender) // 데미지를 주는 과정
	{
		// 공격 데미지 설정
		Interface::diceMessage();
		Interface::WAIT();

		int attack_damage = Dice::rolltheDice(2, 20);
		int defense_chance = Dice::rolltheDice(20);
		cout << "주사위 결과 : " <<attack_damage << endl;

		// 공격 (체력 감소)
		if (attack_damage > defense_chance) {
			defender->getData()->cur_hp -= attack_damage;
			//사망자 발생 시 배틀 종료
			if(this->isDead(defender)) return;
		}
		// 회피
		else
			;

		cout << "공격한 새기 체력 : " << attacker->getData()->cur_hp << "수비한 새기 체력" << defender->getData()->cur_hp << endl;
		//턴 넘기기
		this->exchangeTurn(attacker, defender);
	}

	void exchangeTurn(Unit* attacker, Unit* defender) { // 턴넘기기

		cout << "턴을 넘깁니다." << endl;
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







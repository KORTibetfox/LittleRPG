#pragma once

#include <iostream>
#include <random>
#include "Unit.h"

//temp library
#include <conio.h>
#define MAX(a,b) a > b ? a : b

using namespace std;

//Game Manager : Singleton ���α׷����� �� �ϳ��� ����
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
		cout << "�ƹ� Ű�� ���� �ֻ����� ��������." <<endl;
	}
};

class Battle
{
private:

	void setFirstAttacker(Unit* player, Unit* mob) // ������ ���ϱ�
	{
		Interface::diceMessage();
		Interface::WAIT();

		cout << "�־ȶ�!" <<endl;

		int player_result = Dice::rolltheDice(20);
		int mob_result = Dice::rolltheDice(20);

		cout << "����� �� : " << player_result << " �� �� : " << mob_result << endl;

		if (player_result >= mob_result) {
			cout << "����� ���� �����մϴ�!" << endl;
			this->executeAttack(player, mob);
		}
		else if (player_result < mob_result) {

			cout << "��밡 ���� �����մϴ�!" << endl;
			this->executeAttack(mob, player);
		}
	}

	bool isDead(Unit* unit)
	{
		if (unit->getData()->cur_hp <= 0)
		{
		cout << "������ ����߽��ϴ�." << endl;
		return true;
		}
		return false;
	}

	void executeAttack(Unit* attacker, Unit* defender) // �������� �ִ� ����
	{
		// ���� ������ ����
		Interface::diceMessage();
		Interface::WAIT();

		int attack_damage = Dice::rolltheDice(2, 20);
		int defense_chance = Dice::rolltheDice(20);
		cout << "�ֻ��� ��� : " <<attack_damage << endl;

		// ���� (ü�� ����)
		if (attack_damage > defense_chance) {
			defender->getData()->cur_hp -= attack_damage;
			//����� �߻� �� ��Ʋ ����
			if(this->isDead(defender)) return;
		}
		// ȸ��
		else
			;

		cout << "������ ���� ü�� : " << attacker->getData()->cur_hp << "������ ���� ü��" << defender->getData()->cur_hp << endl;
		//�� �ѱ��
		this->exchangeTurn(attacker, defender);
	}

	void exchangeTurn(Unit* attacker, Unit* defender) { // �ϳѱ��

		cout << "���� �ѱ�ϴ�." << endl;
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







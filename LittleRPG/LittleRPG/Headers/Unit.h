#pragma once
#include <string>
#include <iostream>

using namespace std;

typedef struct Data
{
	string name;

	short int level;
	short int exp;
	short int cur_hp; // current hp
	short int max_hp;

	short int str; // Strength
	short int dex; // Dexterity
	short int vit; // Vitality

	short int bonus_preemptive; // who first punch shit boy
	short int bonus_damage;
	short int bonus_dodge;

}Data;

class Unit
{
private:

protected:
	Data data;

public:
	Unit()
	{
		// All Units must have below indexes
		this->data.level = 1;
		this->data.exp = 0;
		this->data.cur_hp = 200;
		this->data.max_hp = 200;
		this->data.str = 8;
		this->data.dex = 8;
		this->data.vit = 8;
		
	}

	virtual ~Unit() {}

	Data getData()
	{
		return data;
	}

	void setCurHp(int damage) { this->data.cur_hp -= damage; }
};

class Player : public Unit
{
public:
	Player() : Unit()
	{
		this->data.name = "Zeus";
		//stats
		this->data.str = 10;
		this->data.dex = 8;
		this->data.vit = 8;

		this->data.bonus_damage = int(this->data.str / 2);
		this->data.bonus_preemptive = int(this->data.dex / 2);
		this->data.bonus_dodge = int(this->data.vit / 2);
	}
};

class Mob : public Unit
{
public:
	// Common enemy
	Mob(string name, int level, int max_hp, int str, int dex, int vit) : Unit()
	{
		this->data.name = name;
		this->data.level = level;
		this->data.cur_hp = this->data.max_hp = max_hp;
		this->data.str = str;
		this->data.dex = dex;
		this->data.vit = vit;

		this->data.bonus_damage = int(this->data.str / 2);
		this->data.bonus_preemptive = int(this->data.dex / 2);
		this->data.bonus_dodge = int(this->data.vit / 2);
	}
};

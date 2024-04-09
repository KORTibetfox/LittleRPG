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

	short int preemptive; // who first punch shit boy 

}Data;

class Unit
{
private:

protected:
	Data* data;

public:
	Unit() 
	{
		// All Units must have below indexes
		data->level = 1;
		data->exp = 0;
		data->cur_hp = 10;
		data->max_hp = 10;
		data->str = 8;
		data->dex = 8;
		data->vit = 8;
	}

	virtual ~Unit() {}

	Data* getData()
	{
		return data;
	}
};

class Player : public Unit
{
public:
	Player() 
	{ 
		this->data->name = "Zeus"; 
		//stats
		this->data->str = 8;
		this->data->dex = 8;
		this->data->vit = 8;
	}
};

class Mob : public Unit
{
public:
	// Common enemy
	Mob(string name, int level, int max_hp, int str, int dex, int vit)
	{
		data->name = name;
		data->level = level;
		data->max_hp = max_hp;
		data->str = str;
		data->dex = dex;
		data->vit = vit;
	}
};


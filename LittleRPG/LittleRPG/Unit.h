#pragma once
#include <string>
#include <iostream>

using namespace std;

typedef struct Data
{
	string name;

	short int level;
	short int exp;
	short int cur_hp; // 현재 체력
	short int max_hp; // 최대 체력

	short int str; // 근력
	short int dex; // 민첩
	short int vit; // 방어

}Data;

class Unit
{
private:

protected:
	Data* data;

public:
	Unit() 
	{
		//기본 유닛
		data->level = 1;
		data->exp = 0;
		data->cur_hp = 0;
		data->max_hp = 10;
		data->str = 8;
		data->dex = 8;
		data->vit = 8;
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
	// 스킬 없는 노멀 유닛 생성
	Mob(int level, int max_hp, int str, int dex, int vit)
	{
		data->level = level;
		data->max_hp = max_hp;
		data->str = str;
		data->dex = dex;
		data->vit = vit;
	}
};


#pragma once
#include <string>
#include <iostream>

using namespace std;

typedef struct Data
{
	string name;

	short int level;
	short int exp;
	short int cur_hp; // ���� ü��
	short int max_hp; // �ִ� ü��

	short int str; // �ٷ�
	short int dex; // ��ø
	short int vit; // ���

	short int preemptive; //������

}Data;

class Unit
{
private:

protected:
	Data* data;

public:
	Unit() 
	{
		//�⺻ ����
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
	// ��ų ���� ��� ���� ����
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


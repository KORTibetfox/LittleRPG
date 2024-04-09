#pragma once

#include <iostream>
#include <random>

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

class Dice
{
private:

public:
	int getRandomNumber(int range)
	{
		int r;
		random_device rd;
		mt19937 gen(rd());

		uniform_int_distribution<int> dis(0,99);

		return r;
	}

	void rolltheDice() 
	{

	}

};

class Battle
{
private:

public:

};


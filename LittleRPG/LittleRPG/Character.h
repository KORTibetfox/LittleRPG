#pragma once

#include <string>
#include <iostream>

using namespace std;

class Character {

private:

protected:
	string class_name;
	int skill_point;
public:

	virtual ~Character() {};
};

class Warrior : public Character {

	Warrior()
	{
		this->class_name = "전사";	
	}

};

class Wizard : public Character {

	Wizard() {
		this->class_name = "마법사";
	}

};

class Archer : public Character {

	Archer() {
		this->class_name = "궁수";
	}
};
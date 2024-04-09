#pragma once

#include <string>
#include <iostream>

using namespace std;

class Character {

private:

protected:
	string class_name;

public:

	string getClassName() { return this->class_name; }

	virtual ~Character() {}

};

class Warrior : public Character {

public:

	Warrior()
	{
		this->class_name = "����";	
	}

};

class Wizard : public Character {

public:
	Wizard() {
		this->class_name = "������";
	}

};

class Archer : public Character {

public:
	Archer() {
		this->class_name = "�ü�";
	}
};
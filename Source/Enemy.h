#pragma once

#include <string>

using namespace std;

class Enemy {
public:
	Enemy() = default;
	virtual compl Enemy() = default;
	
	string name;
	int hp, atk, mag, exp, maxHp, level;
};

class Dummy : public Enemy {
public:
	Dummy() = default;
	virtual compl Dummy() = default;
};


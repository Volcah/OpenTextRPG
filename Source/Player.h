#pragma once

#include <string>

using namespace std;

class Player final {
public:
	Player() = default;
	virtual compl Player() = default;
	
	string name, surname, playerclass;
	int hp, atk, mag, exp, maxHp, level, nextlevel, actualZone, x, y;
};

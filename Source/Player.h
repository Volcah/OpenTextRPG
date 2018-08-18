#pragma once

#include <string>

class Player
{
public:
    std::string name, surname, playerclass;
	int hp, atk, mag, exp, maxHp,
        level, nextlevel, actualZone;
    Player();
};

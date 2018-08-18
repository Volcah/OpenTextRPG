#pragma once

#include <string>

class Enemy
{
public:
    std::string name;
	int hp, atk, mag, exp, maxHp, level;
    Enemy();
};

class Dummy : public Enemy
{
public:
    Dummy();
};


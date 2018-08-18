#include "Enemy.h"

Enemy::Enemy()
{
    name = "EnemyTest";
    hp = 50;
	atk = 20;
	mag = 20;
	exp = 25;
	maxHp = hp;
	level = 1;
}

Dummy::Dummy()
{
    name = "Dummy";
    hp = 105;
	atk = 1;
	level = 1;
	exp = 15;
	maxHp = 105;
}

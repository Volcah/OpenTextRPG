#pragma once

#include <iostream>
#include <ctime>
#include <fstream>

#include "Player.h"
#include "Enemy.h"
#include "Game.h"

class Engine
{
public:
    Engine();
    void Battle(Enemy enemy);
    void Battle(Dummy dummy);
    void Start();
    void Play();
    void Save();
    void Load();
    void PlayerUp();
    void Stats();
    void Magic(Enemy& enemy);
    void Magic(Dummy& dummy);
    void Randomize();
    void ChooseClass();
    void Summary();
    void TrainingZone1();
    void TrainingZone2();
    void TrainingZoneBattle();
};

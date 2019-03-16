#pragma once

#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
#include <iterator>

#include "Player.h"
#include "Enemy.h"
#include "Game.h"
#include "Location.h"
#include "Item.h"

class Engine final {
public:
    Engine() = default;
    virtual compl Engine() = default;
    
    void CreateItems();
    void Battle(Enemy enemy);
    void Battle(Dummy dummy);
    void Start();
    void Play();
    void Save();
    void Load();
    void Pause();
    void PlayerUp();
    void Stats();
    void Magic(Enemy& enemy);
    void Magic(Dummy& dummy);
    void Items();
    void Randomize();
    void ChooseClass();
    void Summary();
    void TrainingZone1();
    void TrainingZone2();
    void TrainingZoneBattle();
    template <size_t rows, size_t columns>
    void UpdateDungeon(string (&iDungeon)[rows][columns]);
};

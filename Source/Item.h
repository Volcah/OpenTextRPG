#pragma once

#include <string>
#include <iostream>
#include "Player.h"

using namespace std;

class Item {
public:
    Item() = default;
    virtual compl Item() = default;
    
    string name, description;
    int value, position, num, id;
    
    void Add(Item item);
    void Remove(Item item);
    void Show();
};

class Cure: public Item {
public:
    Cure() = default;
    explicit inline Cure(string newName, string newDescription, int newValue, int newCurePoints);
    virtual compl Cure() = default;
    
    int CurePoints;
    void Use(Player player);
};



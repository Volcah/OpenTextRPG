#pragma once

#include <string>
#include <iostream>
#include "Player.h"

using namespace std;

class Item
{
public:
    string name, description;
    int value, position, num, id;
    Item();
    void Add(Item item);
    void Remove(Item item);
    void Show();
};

class Cure: public Item
{
public:
    int CurePoints;
    void Use(Player player);
    Cure(string newName, string newDescription, int newValue, int newCurePoints);
};



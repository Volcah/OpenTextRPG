#include "Item.h"
#include "Game.h"

void Item::Add(Item item)
{
    if(item.num < 10)
        item.num++;
}

void Item::Remove(Item item)
{
    if(item.num > 0)
        item.num--;
}

void Item::Show()
{
    rlutil::cls();
    std::cout << "Name: " << name << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Value: " << value << std::endl;

}

Cure::Cure(string newName, string newDescription, int newValue, int newCurePoints)
{
    name = newName;
    description = newDescription;
    value = newValue;
    CurePoints = newCurePoints;
}

void Cure::Use(Player player)
{
    player.hp += Cure::CurePoints;
    if(player.hp > player.maxHp)
        player.hp = player.maxHp;
    std::cout << player.name << " gained " << Cure::CurePoints << " HP.\n";
    std::cout << player.name << " HP = " << player.hp << std::endl;
}

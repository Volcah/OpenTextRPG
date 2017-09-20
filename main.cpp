#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

//Inizializzazione delle variabili.giocatore.
string name;
string surname;
string playerclass;

//Inizializzazione delle statistiche
int hp, atk, mag, level, exp;


//Inizializzazione delle funzioni.
void menu();
void play();
void settings();
void chooseclass();
void summary();

//Training zone
void training_zone_1();
void training_zone_2();

//Programma principale.
int main(int argc, char* argv[])
{
    system("cls");
    menu();
}

//Menu principale.
void menu(){
    system("cls");
    int selection;
    cout << "Welcome to OpenTextRPG.\n\nSelect an option.\n\n\t1-Play\n\t2-Settings\n\t3-Exit\n\n";
    cin >> selection;
    switch(selection){
    case(1):
        play();
        break;
    case(2):
        settings();
        break;
    case(3):
        exit(0);
        break;
    }
}

//Inizio gioco, salvataggi WIP.
void play(){
    system("cls");
    int selection;
    cout << "Choose a name.\n\n";
    cin >> name;
    cout << "\nChoose a surname.\n\n";
    cin >> surname;
    cout << "\nSo, you are " << name << " " << surname << "?\n\nPress 1 for yes, 0 for no.\n\n";
    cin >> selection;
    switch(selection){
    case(1):
        chooseclass();
        break;
    default:
        play();
        break;
    }
}

//Impostazioni, WIP.
void settings(){
    system("cls");
    int selection;
    cout << "Still Work in Progress.\n";
    system("PAUSE");
    menu();
}

//Selezione della classe.
void chooseclass(){
    system("cls");
    int selection;
    cout << "Ok, now choose a class.\n\n\t1-Archer\n\t2-Knight\n\t3-Mage\n\t4-Warrior\n";
    cin >> selection;
    switch(selection){
    case(1):
        playerclass = "Archer";
        break;
    case(2):
        playerclass = "Knight";
        break;
    case(3):
        playerclass = "Mage";
        break;
    case(4):
        playerclass = "Warrior";
        break;
    }
    int confirm;
    cout << "\nSo, you are " << name << " " << surname << ", the " << playerclass << "?\n\nPress 1 for yes, 0 for no.\n\n";
    cin >> confirm;
    if(confirm == 1){
        summary();
        exit(0);
    }else{
        chooseclass();
    }

}

void summary(){
    system("cls");
    int selection;
    cout << "This is a summary of your choices\n\nName: " << name << "\nSurname: " << surname << "\nClass: " << playerclass << "\nHealth Points: " << hp << "\nAttack: " << atk << "\nMagic: " << mag << "\n\n";
    cout << "Do you want to edit something?\n\t1-Name and Surname\n\t2-Class\n\t3-Go ahead\n\t4-Main Menu\n\n";
    cin >> selection;
    switch(selection){
    case(1):
        play();
        break;
    case(2):
        chooseclass();
        break;
    case(3):
        training_zone_1();
        break;
    case(4):
        menu();
        break;
    default:
        summary();
        break;
    }
}

void training_zone_1(){
    system("cls");
    int selection;
    cout << "Trainer:\nWelcome to the Training Zone, I will teach you how to survive out of the safe\nzones.\n";
    getch();
    system("cls");
    cout << "Trainer:\nNow, tell me what do you want to learn, please.\n\t1-Attack\n\t2-Magic\n\t3-Special\n\t4-Nothing, thanks.\n";
    cin >> selection;
    switch(selection){
    case(1):
        system("cls");
        cout << "Trainer:\nWhen attacked by one or more enemies, you should give it right back to 'em.\nChoose Attack when the Battle Menu shows up";
        getch();
        training_zone_1();
        break;
    case(2):
        system("cls");
        cout << "Trainer:\nUnlike the Attack, the magic has multiple purposes. In fact, magic can\nserve to attack, but also to heal yourself or to confuse the enemy.";
        getch();
        training_zone_1();
        break;
    case(3):
        system("cls");
        cout << "Trainer:\nAs the name says, they are attacks/spells very powerful that can only be\nused once in battle.";
        getch();
        training_zone_1();
        break;
    case(4):
        training_zone_2();
        break;
    default:
        training_zone_1();
        break;
    }
}

void training_zone_2(){
    cout << "Work in progress";
}

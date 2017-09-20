#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

//Inizializzazione delle variabili.
string name;
string surname;
string playerclass;

//Inizializzazione delle funzioni.
void menu();
void play();
void settings();
void chooseclass();

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
    cout << "Work in Progress\n";
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
        //WIP;
        exit(0);
    }else{
        chooseclass();
    }

}


#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <istream>

using namespace std;

//Inizializzazione delle variabili.giocatore.
struct Player{
    string name;
    string surname;
    string playerclass;
    int hp, atk, mag, exp;
    int level = 1;
    int nextlevel = 15;
};

Player player;



//Nemici
struct Dummy{
    string name = "Dummy";
    int hp = 105;
    int atk = 0;
    int level = 1;
    int exp = 15;
};

Dummy dummy;

//Inizializzazione delle zone principali.
void menu();
void play();
void settings();
void chooseclass();
void summary();
void statistics();
void playerup();

//Training zones
void training_zone_1();
void training_zone_2();
void training_zone_battle();
void training_zone_finish();

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
    default:
        menu();
        break;
    }
}

//Inizio gioco, salvataggi WIP.
void play(){
    system("cls");
    int selection;
    cout << "Choose a name.\n\n";
    cin.ignore();
    getline(cin, player.name);
    cout << "\nChoose a surname.\n\n";
    getline(cin, player.surname);
    cout << "\nSo, you are " << player.name << " " << player.surname << "?\n\nPress 1 for yes, 0 for no.\n\n";
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
    cout << "Still Work in Progress.\n";
    getch();
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
        player.playerclass = "Archer";
        player.hp = 20;
        player.atk = 25;
        player.mag = 10;
        break;
    case(2):
        player.playerclass = "Knight";
        player.hp = 70;
        player.atk = 25;
        player.mag = 10;
        break;
    case(3):
        player.playerclass = "Mage";
        player.hp = 30;
        player.atk = 10;
        player.mag = 30;
        break;
    case(4):
        player.playerclass = "Warrior";
        player.hp = 50;
        player.atk = 45;
        player.mag = 10;
        break;
    default:
        chooseclass();
        break;
    }
    int confirm;
    cout << "\nSo, you are " << player.name << " " << player.surname << ", the " << player.playerclass << "?\n\nPress 1 for yes, 0 for no.\n\n";
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
    cout << "This is a summary of your choices\n\nName: " << player.name << "\nSurname: " << player.surname << "\nClass: " << player.playerclass << "\nHealth Points: " << player.hp << "\nAttack: " << player.atk << "\nMagic: " << player.mag << "\n\n";
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
    system("cls");
    int selection;
    cout << "Trainer:\nThis is a dummy, you can use it when you want to train your combat skills.\n";
    cout << "When you're ready, press 1 to start the battle, or press 0 to go back.\n";
    cin >> selection;
    if(selection == 1){
        training_zone_battle();
    }else{
        training_zone_1();
    }
}

void training_zone_battle(){
    system("cls");
    cout << dummy.name << " appears!\n";
    getch();
    while(dummy.hp > 0 & player.hp > 0){
            system("cls");
            int selection;
            cout << player.name << "'s life= " << player.hp << "\n" << dummy.name << "'s life= " << dummy.hp << "\n\n";
            cout << "What do you want to do?\n\t";
            cout << "1-Attack\n\t2-Magic\n\t3-Escape\n\n";
            cin >> selection;
            int enemyattack;
            int escape;
            switch(selection){
            case(1):
                dummy.hp -= player.atk;
                cout << dummy.name << " takes " << player.atk << " damage.\n";
                enemyattack = rand()%2;
                if(enemyattack == 1){
                    player.hp -= dummy.atk;
                    cout << player.name << " takes " << dummy.atk << " damage.\n";
                    getch();
                }else{
                    cout << dummy.name << "'s attack missed!";
                    getch();
                }
                break;
            case(2):
                dummy.hp -= player.mag;
                cout << dummy.name << " takes " << player.mag << " damage.\n";
                enemyattack = rand()%2;
                if(enemyattack == 1){
                    player.hp -= dummy.atk;
                    cout << player.name << " takes " << dummy.atk << " damage.\n";
                    getch();
                }else{
                    cout << dummy.name << "'s attack missed!";
                    getch();
                }
                break;
            case(3):
                escape = rand()%4;
                if(escape == 1){
                    cout << "You successfully escaped.\n";
                    getch();
                    training_zone_finish();
                }else{
                    enemyattack = rand()%2;
                    if(enemyattack == 1){
                        player.hp -= dummy.atk;
                        cout << player.name << " takes " << dummy.atk << " damage.\n";
                        getch();
                    }else{
                        cout << dummy.name << "'s attack missed!";
                        getch();
                    }
                }
                break;
            default:
                enemyattack = rand()%2;
                if(enemyattack == 1){
                    player.hp -= dummy.atk;
                    cout << player.name << " takes " << dummy.atk << " damage.\n";
                    getch();
                }else{
                    cout << dummy.name << "'s attack missed!";
                }
                break;

            }
    }
    while(player.hp <= 0){

            cout << player.name << "dies.\n";
            cout << "Game Over, HOW did you arrive here?";
            getch();
            training_zone_battle();
    }
    system("cls");
    cout << dummy.name << " dies.\n";
    getch();
    player.exp += dummy.exp;
    cout << "\n" << player.name << " gains " << dummy.exp << " experience points.\n\n";
    getch();
    system("cls");
    if(player.exp >= player.nextlevel){
        playerup();
    }
    training_zone_finish();

}

void statistics(){
    cout << player.name << " " << player.surname << "'s statistics." << endl;
    cout << "\tClass: " << player.playerclass << endl;
    cout << "\tLevel: " << player.level << endl;
    cout << "\tExperience Points: " << player.exp << endl;
    cout << "\tExperience Points to the next level: " << player.nextlevel << endl;
    cout << "\tHealth Points: " << player.hp << endl;
    cout << "\tAttack points: " << player.atk << endl;
    cout << "\tMagic points: " << player.mag << endl;
    getch();
}

void training_zone_finish(){
    system("cls");
    cout << "Congratulations, you finished the alpha. Here's a virtual cup for you.\n";
    getch();
    exit(0);
}

void playerup(){
    player.level++;
    player.nextlevel = player.nextlevel *= 2;
    cout << player.name << " leveled up!\n\n";
    switch(player.level){
    case(2):
        player.hp += 10;
        player.atk += 5;
        player.mag += 10;
        break;
    case(3):
        player.hp += 10;
        player.atk += 5;
        player.mag += 10;
        break;
    case(4):
        player.hp += 15;
        player.atk += 10;
        player.mag += 15;
        break;
    }
    statistics();
}

#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#include <string>
#include <istream>

//Including rlutil.h
#include "game.h"

#define waitkey rlutil::anykey("Press any key to continue...")

using namespace std;
using namespace rlutil;

//Inizializzazione delle variabili giocatore.
struct Player{
    string name = "Player";
    string surname;
    string playerclass = "Test";
    int hp = 50, atk = 20, mag = 20, exp = 0, maxHp = 50;
    int level = 1;
    int nextlevel = 15;
};

Player player;

//Inizializzazione variabili nemico.
struct Dummy{
    string name = "Dummy";
    int hp = 105;
    int atk = 1;
    int level = 1;
    int exp = 15;
    int maxHp = 105;
};

Dummy dummy;

//Inizializzazione oggetti/inventario.
struct Items{
    int potion = 1;
};

Items items;

//Inizializzazione delle zone principali.
void menu();
void play();
void settings();
void chooseClass();
void summary();
void statistics();
void playerUp();
void inventory();
void magic();
void resetHealth();
void msg(string name, string message);

//Training zone
void training_zone_1();
void training_zone_2();
void training_zone_battle();
void training_zone_finish();

//Battle zones
void randomizeBattle();
void random_battle();

//Programma principale.
int main(int argc, char* argv[])
{
    cls();
    menu();
}

//Menu principale.
void menu(){
    saveDefaultColor();
    cls();
    int selection = 1;
    cout << "Welcome to OpenTextRPG.\n\n" ;
    cout << "Select an option.\n\n";
    setColor(2);
    cout << "\t1-Play\n";
    cout << "\t2-Random Battle\n";
    resetColor();
    cout << "\t3-Settings\n";
    cout << "\t4-Exit\n\n";
    cin >> selection;
    switch(selection){
        case(1):
            play();
            break;
        case(2):
            randomizeBattle();
            break;
        case(3):
            settings();
            break;
        case(4):
            exit(0);
        default:
            cin.clear();// Per ignorare caratteri come ^Z, ecc.
            menu();
            break;
    }
}

//Inizio gioco, salvataggi WIP.
void play(){
    cls();
    int selection = 1;
    cout << "Choose a name.\n\n";
    cin.ignore();
    getline(cin, player.name);
    cout << "\nChoose a surname.\n\n";
    getline(cin, player.surname);
    cout << "\nSo, you are " << player.name << " " << player.surname << "?\n\nPress 1 for yes, 0 for no.\n\n";
	cin >> selection;
    switch(selection){
        case(1):
            chooseClass();
            break;
        default:
            play();
            break;
    }
}

//Impostazioni, WIP.
void settings(){
    cls();
    cout << "Still Work in Progress.\n";
    getch();
    menu();
}

//Selezione della classe.
void chooseClass(){
    cls();
	int selection = 1;
    cout << "Ok, now choose a class.\n\n\t1-Archer\n\t2-Knight\n\t3-Mage\n\t4-Warrior\n";
	cin >> selection;
    switch(selection){
        case(1):
            player.playerclass = "Archer";
            player.hp = 20;
            player.atk = 25;
            player.mag = 10;
            player.maxHp = player.hp;
            break;
        case(2):
            player.playerclass = "Knight";
            player.hp = 70;
            player.atk = 25;
            player.mag = 10;
            player.maxHp = player.hp;
            break;
        case(3):
            player.playerclass = "Mage";
            player.hp = 30;
            player.atk = 10;
            player.mag = 30;
            player.maxHp = player.hp;
            break;
        case(4):
            player.playerclass = "Warrior";
            player.hp = 50;
            player.atk = 45;
            player.mag = 10;
            player.maxHp = player.hp;
            break;
        default:
            chooseClass();
            break;
    }
    int confirm;
    cout << "\nSo, you are " << player.name << " " << player.surname << ", the " << player.playerclass << "?\n\nPress 1 for yes, 0 for no.\n\n";
	cin >> confirm;
    if(confirm == 1){
        summary();
        exit(0);
    }else{
        chooseClass();
    }

}

//Riassunto delle scelte.
void summary(){
    cls();
    int selection = 1;
    cout << "This is a summary of your choices\n\nName: " << player.name << "\nSurname: " << player.surname;
    setColor(14);
    cout << "\nClass: " << player.playerclass;
    setColor(2);
    cout <<  "\nHealth Points: " << player.hp;
    setColor(4);
    cout << "\nAttack: " << player.atk;
    setColor(1);
    cout << "\nMagic: " << player.mag << "\n\n";
    resetColor();
    cout << "Do you want to edit something?\n\t1-Name and Surname\n\t2-Class\n\t3-Go ahead\n\t4-Main Menu\n\n";
	cin >> selection;
    switch(selection){
        case(1):
            play();
            break;
        case(2):
            chooseClass();
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
    cls();
	int selection = 1;
    msg("Trainer", "\nWelcome to the Training Zone, I will teach you how to survive out of the safe\nzones.\n");
    getch();
    cls();
    msg("Trainer","\nNow, tell me what do you want to learn, please.\n\t1-Attack\n\t2-Magic\n\t3-Special\n\t4-Nothing, thanks.\n");
	cin >> selection;
    switch(selection){
        case(1):
            cls();
            msg("Trainer", "\nWhen attacked by one or more enemies, you should give it right back to 'em.\nChoose Attack when the Battle Menu shows up");
            getch();
            training_zone_1();
            break;
        case(2):
            cls();
            msg("Trainer", "\nUnlike the Attack, the magic has multiple purposes. In fact, magic can\nserve to attack, but also to heal yourself or to confuse the enemy.");
            getch();
            training_zone_1();
            break;
        case(3):
            cls();
            msg("Trainer", "\nAs the name says, they are attacks/spells very powerful that can only be\nused once in battle.");
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
    cls();
	int selection = 1;
    msg("Trainer","\nThis is a dummy, you can use it when you want to train your combat skills.\nWhen you're ready, press 1 to start the battle, or press 0 to go back.\n");
	cin >> selection;
    if(selection == 1){
        training_zone_battle();
    }else{
        training_zone_1();
    }
}

void training_zone_battle(){
    cls();
    dummy.hp = dummy.maxHp;
    setColor(5);
    cout << dummy.name << " appears!\n";
    resetColor();
	waitkey;
    int enemyAttack = 1;
    while(dummy.hp > 0 && player.hp > 0){
        cls();
        int selection = 1;
        setColor(2);
        cout << player.name << "'s life= " << player.hp << endl;
        setColor(4);
        cout << dummy.name << "'s life= " << dummy.hp << "\n\n";
        resetColor();
        cout << "What do you want to do?\n\t";
        cout << "1-Attack\n\t2-Magic\n\t3-Escape\n\t4-Inventory\n\n";
		int escape;
		cin >> selection;
        switch(selection){
            case(1):
                dummy.hp -= player.atk;
                setColor(1);
                cout << dummy.name << " takes " << player.atk << " damage.\n";
                enemyAttack = rand()%2;
                if(enemyAttack == 1 && dummy.hp > 0){
                    player.hp -= dummy.atk;
                    setColor(4);
                    cout << player.name << " takes " << dummy.atk << " damage.\n";
                    resetColor();
                    getch();
                }else{
                    setColor(3);
                    cout << dummy.name << "'s attack missed!";
                    resetColor();
                    getch();
                }
                break;
            case(2):
                magic();
                if(enemyAttack == 1 && dummy.hp > 0){
                    player.hp -= dummy.atk;
                    setColor(4);
                    cout << player.name << " takes " << dummy.atk << " damage.\n";
                    resetColor();
                    getch();
                }else{
                    setColor(3);
                    cout << dummy.name << "'s attack missed!";
                    resetColor();
                    getch();
                }
                break;
            case(3):
                escape = rand()%4;
                if(escape == 1){
                    setColor(9);
                    cout << "You successfully escaped.\n";
                    resetColor();
                    getch();
                    training_zone_finish();
                }else{
                    enemyAttack = rand()%2;
                    if(enemyAttack == 1 && dummy.hp > 0){
                        player.hp -= dummy.atk;
                        setColor(4);
                        cout << player.name << " takes " << dummy.atk << " damage.\n";
                        resetColor();
                        getch();
                    }else{
                        setColor(3);
                        cout << dummy.name << "'s attack missed!";
                        resetColor();
                        getch();
                    }
                }
                break;
            case(4):
                inventory();
            default:
                enemyAttack = rand()%2;
                if(enemyAttack == 1 && dummy.hp > 0){
                    player.hp -= dummy.atk;
                    setColor(4);
                    cout << player.name << " takes " << dummy.atk << " damage.\n";
                    resetColor();
                    getch();
                }else{
                    setColor(3);
                    cout << dummy.name << "'s attack missed!";
                    resetColor();
                }
                break;

        }
    }
    while(player.hp <= 0){
        setColor(5);
        cout << player.name << "dies.\n";
        resetColor();
        cout << "Game Over, HOW did you arrive here?";
        getch();
        resetHealth();
        training_zone_battle();
    }
    cls();
    setColor(2);
    cout << dummy.name << " dies.\n";
    resetColor();
    getch();
    player.exp += dummy.exp;
    setColor(14);
    cout << "\n" << player.name << " gains " << dummy.exp << " experience points.\n\n";
    cout << player.name << " gains " << 2 * player.level << " health points.\n\n";
    if(player.hp > player.maxHp)
        player.hp += (player.level * 2);
    resetColor();
    getch();
    cls();
    if(player.exp >= player.nextlevel){
        playerUp();
    }
    training_zone_finish();

}

//Statistiche giocatore.
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

//WIP.
void training_zone_finish(){
    cls();
    cout << "Congratulations, you finished the alpha. Here's a virtual cup for you.\n";
    getch();
    exit(0);
}


//Sistema di livellaggio.
void playerUp(){
    player.level++;
    player.nextlevel = player.nextlevel *= 2;
    setColor(9);
    cout << player.name << " leveled up!\n\n";
    resetColor();
    switch(player.level){
        case(2):
            player.hp += 10;
            player.atk += 5;
            player.mag += 10;
            player.maxHp = player.hp;
            break;
        case(3):
            player.hp += 10;
            player.atk += 5;
            player.mag += 10;
            player.maxHp = player.hp;
            break;
        case(4):
            player.hp += 15;
            player.atk += 10;
            player.mag += 15;
            player.maxHp = player.hp;
            break;
        default:
            break;
    }
    statistics();
}

//Inventario.
void inventory(){
    cls();
    int selection = 1;
    cout << "You have:\n\t";
    cout << items.potion << " Potion/s\n";
    cout << "\nWhat do you want to use?\n\t";
    cout << "1-Potion\n\t2-Exit\n";
    
    
    switch(selection){
        case(1):
            player.hp +=20;
            if(player.hp > player.maxHp){
                player.hp = player.maxHp;
            }
            setColor(2);
            cout << player.name << " heals " << player.mag << " HP.\n";
            resetColor();
            getch();
            break;
        case(2):
            break;
        default:
            inventory();
    }
}

//Menu' scelta magie.
void magic(){
    cls();
    int selection = 1;
    cout << "Select a spell.\n\t1-Cure\n\t2-Fireball\n\t3-Exit\n";
	cin >> selection;
    switch(selection){
        case(1):
            player.hp += player.mag;
            if(player.hp > player.maxHp){
                player.hp = player.maxHp;
            }
            setColor(2);
            cout << player.name << " heals " << player.mag << " HP.\n";
            resetColor();
            getch();
        case(2):
            dummy.hp -= player.mag;
            setColor(4);
            cout << "Dummy takes " << player.mag << " of magical damage!\n\n";
            resetColor();
            getch();
            break;
        case(3):
            break;
        default:
            break;
    }
}

void msg(string name, string message){
    cout << name << ": " << message;
}

void randomizeBattle(){
    cls();
    cout << "Randomizing..." << endl;
    srand(time(NULL));
    player.atk = rand() % 25 + 1;
    player.hp = rand() % 100 + 1;
    player.mag = rand() % 30 + 1;
    player.maxHp = player.hp;

    dummy.atk = rand() % 30 + 1;
    dummy.hp = rand() % 100 + 1;
    dummy.maxHp = dummy.hp;

    cout << "Succesfully randomized." << endl;

    cout << "Player's Health Points: " << player.hp << endl;
    cout << "Player's Attack points: " << player.atk << endl;
    cout << "Player's Magic points: " << player.mag << endl << endl;

    cout << "Enemy's Health Points: " << dummy.hp << endl;
    cout << "Enemy's Attack points: " << dummy.atk << endl;

    getch();

    random_battle();
}

void random_battle(){
    cls();
    dummy.hp = dummy.maxHp;
    setColor(5);
    cout << dummy.name << " appears!\n";
    resetColor();
	waitkey;
    int enemyAttack = 1;
    while(dummy.hp > 0 && player.hp > 0){
        cls();
        int selection = 1;
        setColor(2);
        cout << player.name << "'s life= " << player.hp << endl;
        setColor(4);
        cout << dummy.name << "'s life= " << dummy.hp << "\n\n";
        resetColor();
        cout << "What do you want to do?\n\t";
        cout << "1-Attack\n\t2-Magic\n\t3-Escape\n\t4-Inventory\n\n";
        int escape;
		cin >> selection;
        switch(selection){
            case(1):
                dummy.hp -= player.atk;
                setColor(1);
                cout << dummy.name << " takes " << player.atk << " damage.\n";
                enemyAttack = rand()%2;
                if(enemyAttack == 1 && dummy.hp > 0){
                    player.hp -= dummy.atk;
                    setColor(4);
                    cout << player.name << " takes " << dummy.atk << " damage.\n";
                    resetColor();
                    getch();
                }else{
                    setColor(3);
                    cout << dummy.name << "'s attack missed!";
                    resetColor();
                    getch();
                }
                break;
            case(2):
                magic();
                if(enemyAttack == 1 && dummy.hp > 0){
                    player.hp -= dummy.atk;
                    setColor(4);
                    cout << player.name << " takes " << dummy.atk << " damage.\n";
                    resetColor();
                    getch();
                }else{
                    setColor(3);
                    cout << dummy.name << "'s attack missed!";
                    resetColor();
                    getch();
                }
                break;
            case(3):
                escape = rand()%4;
                if(escape == 1){
                    setColor(9);
                    cout << "You successfully escaped.\n";
                    resetColor();
                    getch();
                    menu();
                }else{
                    enemyAttack = rand()%2;
                    if(enemyAttack == 1 && dummy.hp > 0){
                        player.hp -= dummy.atk;
                        setColor(4);
                        cout << player.name << " takes " << dummy.atk << " damage.\n";
                        resetColor();
                        getch();
                    }else{
                        setColor(3);
                        cout << dummy.name << "'s attack missed!";
                        resetColor();
                        getch();
                    }
                }
                break;
            case(4):
                inventory();
            default:
                enemyAttack = rand()%2;
                if(enemyAttack == 1 && dummy.hp > 0){
                    player.hp -= dummy.atk;
                    setColor(4);
                    cout << player.name << " takes " << dummy.atk << " damage.\n";

                    resetColor();
                    getch();
                }else{
                    setColor(3);
                    cout << dummy.name << "'s attack missed!";
                    resetColor();
                }
                break;

        }
    }
    while(player.hp <= 0){
        setColor(5);
        cout << player.name << "dies.\n";
        resetColor();
        cout << "Game Over, HOW did you arrive here?";
        getch();
        resetHealth();
        training_zone_battle();
    }
    cls();
    setColor(2);
    cout << dummy.name << " dies.\n";
    resetColor();
    getch();
    menu();
}

void resetHealth(){
    player.hp = player.maxHp;
    dummy.hp = dummy.maxHp;
}
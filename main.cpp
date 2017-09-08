#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
    //zones
    int menu = 1;
    int newgame = 0;
    int newclass = 0;
    int summary = 0;
    int startzone = 0;

    string name;
    string surname;
    string classchosen;
    while(menu == 1){
        gotomenu:
            system("cls");
            int choicemenu;
            cout << "OpenTextRPG\n\nMain Menu\n\nChoose an option.\n\n\t1-Play\n\t2-Exit\n";
            cin >> choicemenu;
            if(choicemenu == 1){
            }
            switch (choicemenu){

            case(1):
                menu = 0;
                newgame = 1;
                break;
            case(2):
                exit(0);
                break;
            default:
                exit(0);
                break;
            }
    }
    while(newgame == 1){
        gotonewgame:
            system("cls");
            int confirmname;
            cout << "Choose a name\n\n";
            cin >> name;
            cout << "\nChoose a surname\n\n";
            cin >> surname;
            cout << "\nSo, you are " << name << " " << surname << "?\n\nInsert 1 for yes, 0 for No\n\n";
            cin >> confirmname;
            if(confirmname == 1){
                newgame = 0;
                newclass = 1;
                break;
            }else{
                system("cls");
                continue;
            }

        }
    while(newclass == 1){
        gotonewclass:
            system("cls");
            int confirmclass;
            int chooseclass;
            cout << "Ok, now choose a class.\n\t1-Archer\n\t2-Knight\n\t3-Mage\n\t4-Warrior\n";
            cin >> chooseclass;
            switch(chooseclass){
            case(1):
                classchosen = "Archer";
                break;
            case(2):
                classchosen = "Knight";
                break;
            case(3):
                classchosen = "Mage";
                break;
            case(4):
                classchosen = "Warrior";
                break;
            }
            cout << "\nSo, you are " << name << " " << surname << ", the " << classchosen << "?\n\nInsert 1 for yes, 0 for no.\n\n";
            cin >> confirmclass;
            if(confirmclass = 1){
                summary = 1;
                newclass = 0;
            }else{
                goto gotonewclass;
            }
    }
    while(summary == 1){
        gotosummary:
            system("cls");
            int editsummary;
            cout << "There is a summary of your choices\n\nName: " << name << "\nSurname: " << surname << "\nClass: " << classchosen << "\n\n";
            cout << "Do you want to edit something?\n\t1-Name and Surname\n\t2-Class\n\t3-Go ahead\n\t4-Main Menu\n\n";
            cin >> editsummary;
            switch(editsummary){
            case(1):
                goto gotonewgame;
                newgame = 1;
                summary = 0;
                break;
            case(2):
                goto gotonewclass;
                newclass = 1;
                summary = 0;
                break;
            case(3):
                goto gotostartzone;
                startzone = 1;
                summary = 0;
                break;
            case(4):
                goto gotomenu;
                menu = 1;
                summary = 0;
                break;
            }
    }
    while(startzone == 1){
        gotostartzone:
            int finish;
            cout << "This is a test\n";
            cin >> finish;
    }
}


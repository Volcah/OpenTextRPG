#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
    int menu = 1;
    int newgame = 0;
    int newcharacter = 0;
    while(menu == 1){
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
    while(newgame = 1){
                system("cls");
                string name;
                string surname;
                int confirmname;
                cout << "Choose a name\n\n";
                cin >> name;
                cout << "\nChoose a surname\n\n";
                cin >> surname;
                cout << "\nSo, you are " << name << " " << surname << "?\n\nInsert 1 for yes, 0 for No\n\n";
                cin >> confirmname;
                if(confirmname == 1){
                        newgame = 0;
                        newcharacter = 1;
                        break;
                }else{
                        system("cls");
                        continue;
                }

        }
    while(newcharacter == 1){
            system("cls");
            int finish;
            cout << "This is a test, press a button to exit.\n";
            cin >> finish;
            exit(0);
    }
}


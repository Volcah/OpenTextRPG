#include "Location.h"

Location::Location()
{
    for(int x = 0; x < 10; x++) {
        Dungeon1[x][0] = "X";
    }
    for(int y = 1; y < 10; y++) {
        Dungeon1[0][y] = "X";
    }
    for(int x = 1; x < 9; x++) {
        for(int y = 1; y < 9; y++) {
            Dungeon1[x][y] = " ";
        }
    }
    for(int x = 1; x < 10; x++) {
        Dungeon1[x][9] = "X";
    }
    for(int y = 1; y < 10; y++) {
        Dungeon1[9][y] = "X";
    }
    Dungeon1[6][5] = "X";
    Dungeon1[4][2] = "X";
}

#include "Engine.h"

Engine iEngine;


int main()
{
    std::cout << "This is a message from the developer:\n"
              << "Hi! Thanks for choosing Open Text RPG.\nThis game is reality thanks "
              << "to my work and the help of its (very small) community "
              << "that supports this project.\nThe source code of the game is free, open and "
              << "editable for everyone, even for commercial purposes.\n"
              << "If you want to reuse the code, please include the LICENSE available "
              << "in the repo of this game. Thanks for the attention.";
    getch();
    iEngine.Start();
    return 0;
}

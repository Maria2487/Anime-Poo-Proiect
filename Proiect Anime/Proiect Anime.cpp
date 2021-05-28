// Proiect Anime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "The High Ground.h"

void main()
{
    while (true)
    {
        Menu();
        switch (toupper(_getch()))
        {
        case '1':
            MenuWatcherReaderInterfata();
            break;
        case '2':
            MenuAdmin();
            break;
        case 'X':
            std::cout << ("Programul s-a incheiat\n");
            exit(0);
        default:
            std::cout << (FORMAT1"\t\b\b\033[0;31mOptiune invalida\033[0m");
            Sleep(1500);
        }
    }
}

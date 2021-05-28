#include "The High Ground.h"
#include "Anime.h"
#include "Manga.h"
#include "AdministrareFisiere.h"

void Menu()
{
    system("cls");
    std::cout << (FORMAT1"|------Meniu Principal-----|\n"
        FORMAT1"|1-Watcher/Reader?         |\n"
        FORMAT1"|2-ADMIN?                  |\n"
        FORMAT1"|X-Exit                    |\n"
        FORMAT1"|--------------------------|\n");
}

void MenuWatcherReader()
{
    system("cls");
    cout << (FORMAT1"|---Meniu Watcher/Reader---|\n"
        FORMAT1"|1-Afisare lista de animeuri                |\n"
        FORMAT1"|2-Actualizare lista de animeuri              |\n"
        FORMAT1"3-Dati o nota unui anime|\n"
        FORMAT1"|R-Meniu principal         |\n"
        FORMAT1"|X-Exit                    |\n"
        FORMAT1"|--------------------------|\n");
}

void MenuAdmin()
{
    system("cls");
    std::cout << (FORMAT1"|------Meniu Admin------|\n"
        FORMAT1"|1-Afisare animeuri existente in lista      |\n"
        FORMAT1"|2-Adaugare anime    |\n"
        FORMAT1"|3-Actualizare lista animeuri|\n"
        FORMAT1"|R-Meniu principal         |\n"
        FORMAT1"|X-Exit                    |\n"
        FORMAT1"|--------------------------|\n");
}


void MenuWatcherReaderInterfata()
{
    /*char option;
    list<Client> listaClienti = AdministrareFisiere::CitesteFisierClienti();
    Client nou;
    while (1)
    {
        system("cls");
        MenuWatcherReader();
        switch (toupper(option = _getch()))
        {
        case '1':
            Client::AfisareListaAbonati(listaClienti);
            _getch();
            break;
        case '2':
            nou = Client::Adauga();
            nou.setCod(Client::RandomCod(listaClienti));
            listaClienti.push_back(nou);
            AdministareFisiere::AdaugaClientFisier(nou);
            _getch();
            break;
        case '3':

            break;

        case 'R':
            return;
        case 'X':
            exit(0);
        default:
            std::cout << (FORMAT1"\t\b\b\033[0;31mOptiune invalida\033[0m");
            Sleep(1500);
        }
    }*/
}


void MenuAdminInterfata()
{
    /*char option;
    while (1)
    {
        system("cls");
        MenuAdmin();
        switch (toupper(option = _getch()))
        {
        case '1':
            break;
        case '2':

            break;
        case '3':

            break;
        case '4':

            break;
        case '5':

            break;
        case 'R':
            return;
        case 'X':
            exit(0);
        default:
            std::cout << (FORMAT1"\t\b\b\033[0;31mOptiune invalida\033[0m");
            Sleep(1500);
        }
    }*/
}


bool ValidareString(const string& s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (!isalpha(s[i]))
            return false;
        if (isspace(s[i]))
            return false;
        if (isdigit(s[i]))
            return false;
    }
    return true;
}

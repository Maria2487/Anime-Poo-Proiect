#include "The High Ground.h"
#include "Anime.h"
#include "Manga.h"
#include "AdministrareFisiere.h"

void go()
{
    cout << "\n\nApasa orice tasta pentru a continua...";
}

void Menu()
{
    system("cls");
    std::cout <<
       (FORMAT1"|-----------Meniu Principal---------|\n"
        FORMAT1"|1-Meniu Urmaritor/Cititor?         |\n"
        FORMAT1"|2-Meniu Admin?                     |\n"
        FORMAT1"|X-Exit                             |\n"
        FORMAT1"|-----------------------------------|\n");
}


void MenuWatcherReader()
{
    system("cls");
    cout <<
       (FORMAT1"|------Meniu Urmaritor/Cititor-----|\n"
        FORMAT1"|1-Meniu Urmaritor?                |\n"
        FORMAT1"|2-Meniu Cititor?                  |\n"
        FORMAT1"|R-Meniu principal                 |\n"
        FORMAT1"|X-Exit                            |\n"
        FORMAT1"|----------------------------------|\n");
}

void MenuWatcher()
{
    system("cls");
    cout << 
       (FORMAT1"|------------Meniu Utilizator-------------|\n"
        FORMAT1"|1-Afisare lista totala de animeuri       |\n"
        FORMAT1"|2-Afisare lista personala de animeuri    |\n"
        FORMAT1"|3-Adaugare in lista personala de animeuri|\n"
        FORMAT1"|4-Dati o nota unui anime                 |\n"
        FORMAT1"|5-Actualizati lista personala de animeuri|\n"
        FORMAT1"|E-Meniu secundar                         |\n"
        FORMAT1"|R-Meniu principal                        |\n"
        FORMAT1"|X-Exit                                   |\n"
        FORMAT1"|-----------------------------------------|\n");
}

void MenuReader()
{
    system("cls");
    cout <<
       (FORMAT1"|---------------Meniu Cititor-------------|\n"
        FORMAT1"|1-Afisare lista totala de mangauri       |\n"
        FORMAT1"|2-Afisare lista personala de mangauri    |\n"
        FORMAT1"|3-Adaugare lista personala de mangauri   |\n"
        FORMAT1"|4-Dati o nota unui manga                 |\n"
        FORMAT1"|5-Actualizati lista personala de mangauri|\n"
        FORMAT1"|E-Meniu secundar                         |\n"
        FORMAT1"|R-Meniu principal                        |\n"
        FORMAT1"|X-Exit                                   |\n"
        FORMAT1"|-----------------------------------------|\n");
}

void MenuAdmin()
{
    system("cls");
    std::cout <<
       (FORMAT1"|-------------Meniu Admin-------------|\n"
        FORMAT1"|1-Afisare animeuri existente in lista|\n"
        FORMAT1"|2-Adaugare anime in lista            |\n"
        FORMAT1"|3-Actualizare lista animeuri         |\n"
        FORMAT1"|4-Afisare mangauri existente in lista|\n"
        FORMAT1"|5-Adaugare manga in lista            |\n"
        FORMAT1"|6-Actualizare lista manga            |\n"
        FORMAT1"|R-Meniu principal                    |\n"
        FORMAT1"|X-Exit                               |\n"
        FORMAT1"|-------------------------------------|\n");
}

void MeniuPrincipal()
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
            MenuAdminInterfata();
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

void MenuWatcherReaderInterfata()
{
    char option;
    while (1)
    {
        system("cls");
        MenuWatcherReader();
        switch (toupper(option = _getch()))
        {
        case '1':
            MenuWatcherInterfata();
            break;
        case '2':
            MenuReaderInterfata();
            break;
        case 'R':
            return;
            break;
        case 'X':
            exit(0);
        default:
            std::cout << (FORMAT1"\t\b\b\033[0;31mOptiune invalida\033[0m");
            Sleep(1500);
        }
    }
}


void MenuWatcherInterfata()
{
    char option;
    list<Anime> listaAnimeuri = AdministrareFisiere::CitesteFisierWatcherAnime();
    list<Anime> listaAdmin = AdministrareFisiere::CitesteFisierAdminAnime();
    Anime nou;
    string nume;
    bool valid;
    int nota;
    while (1)
    {
        system("cls");
        MenuWatcher();
        switch (toupper(option = _getch()))
        {
        case '1':
            Anime::AfisareListaAnime(listaAdmin);
            go();
            _getch();
            break;
        case '2':
            Anime::AfisareListaAnime(listaAnimeuri);
            go();
            _getch();
            break;
        case '3':
            cout << "\n\nLista toatala este:\n\n";
            Anime::AfisareListaAnime(listaAdmin);
            cout << "\n\nLista personala este:\n\n";
            Anime::AfisareListaAnime(listaAnimeuri);
            nou = Anime::AdaugaAnime();

            if (nou.getNume() == "Nespecificat")
            {
                go();
                option = _getch();
                break;
            }
            else
            {
                listaAnimeuri.push_back(nou);
                AdministrareFisiere::AdaugaWatcherFisier(nou);
                listaAnimeuri = AdministrareFisiere::CitesteFisierWatcherAnime();
                for (list<Anime>::iterator it = listaAdmin.begin(); it != listaAdmin.end(); it++)
                {
                    if (nou.getNume() == it->getNume())
                    {
                        it->setNota(nou.getNota());
                    }
                }
                AdministrareFisiere::RescriereFisierAdminAnime(listaAdmin);
                listaAdmin = AdministrareFisiere::CitesteFisierAdminAnime();
            }
            
            go();
            _getch();
            break;
        case '4':
            Anime::AfisareListaAnime(listaAdmin);
            valid = false;
            cout << "Numele animeului pe care doriti sa il notati: ";
            cin.seekg(0, ios::end);
            cin.clear();
            getline(cin, nume);
            for (int i = 0; i < nume.length(); i++)
            {
                if (isspace(nume[i]))
                    nume[i] = '_';
            }
            for (auto& c : nume) c = toupper(c);
            for (list<Anime>::iterator it = listaAdmin.begin(); it != listaAdmin.end(); it++)
            {
                if (nume == it->getNume())
                {
                    cout << "Introduceti nota: ";
                    cin >> nota;
                    it->setNota(nota);
                    valid = true;
                }
            }
            if (valid == false)
                cout << "Animeul introdus nu exista in lista\n";
            else
            {
                AdministrareFisiere::RescriereFisierAdminAnime(listaAdmin);
            }
            
           listaAdmin = AdministrareFisiere::CitesteFisierAdminAnime();
           listaAnimeuri = AdministrareFisiere::CitesteFisierWatcherAnime();
           go();
           _getch();
           break;
        case '5':
            Anime::ActualizareAnimeWatcher();
            listaAnimeuri = AdministrareFisiere::CitesteFisierWatcherAnime();
            go();
            _getch();
            break;
        case 'E':
            return;
            break;
        case 'R':
            MeniuPrincipal();
        case 'X':
            exit(0);
        default:
            std::cout << (FORMAT1"\t\b\b\033[0;31mOptiune invalida\033[0m");
            Sleep(1500);
        }
    }
}

void MenuReaderInterfata()
{
    char option;
    list<Manga> listaMangauri = AdministrareFisiere::CitesteFisierReaderManga();
    list<Manga> listaAdmin = AdministrareFisiere::CitesteFisierAdminManga();
    Manga nou;
    string nume;
    bool valid;
    int nota;
    while (1)
    {
        system("cls");
        MenuReader();
        switch (toupper(option = _getch()))
        {
        case '1':
            Manga::AfisareListaManga(listaAdmin);
            _getch();
            go();
            break;
        case '2':
            Manga::AfisareListaManga(listaMangauri);
            go();
            option = _getch();
            break;
        case '3':
            cout << "\n\nLista totala este:\n\n";
            Manga::AfisareListaManga(listaAdmin);
            cout << "\n\nLista personala este\n\n";
            Manga::AfisareListaManga(listaMangauri);
            nou = Manga::AdaugaManga();
            if (nou.getNume() == "Nespecificat")
            {
                break;
            }
            else
            {
                listaMangauri.push_back(nou);
                AdministrareFisiere::AdaugaReaderFisier(nou);
                listaMangauri = AdministrareFisiere::CitesteFisierReaderManga();
                for (list<Manga>::iterator it = listaAdmin.begin(); it != listaAdmin.end(); it++)
                {
                    if (nou.getNume() == it->getNume())
                    {
                        it->setNota(nou.getNota());
                    }
                }
                AdministrareFisiere::RescriereFisierAdminManga(listaAdmin);
                listaAdmin = AdministrareFisiere::CitesteFisierAdminManga();
            }
           
            go();
            _getch();
            break;
        case '4':
            Manga::AfisareListaManga(listaAdmin);
            valid = false;
            cout << "Numele mangaului pe care doriti sa il notati: ";
            cin.seekg(0, ios::end);
            cin.clear();
            getline(cin, nume);
            for (int i = 0; i < nume.length(); i++)
            {
                if (isspace(nume[i]))
                    nume[i] = '_';
            }
            for (auto& c : nume) c = toupper(c);
            for (list<Manga>::iterator it = listaMangauri.begin(); it != listaMangauri.end(); it++)
            {
                if (nume == it->getNume())
                {
                    cout << "Introduceti nota: ";
                    cin >> nota;
                    it->setNota(nota);
                    valid = true;
                }
            }
            if (valid == false)
                cout << "Mangaul introdus nu exista in lista\n";
            else
            {
                AdministrareFisiere::RescriereFisierAdminManga(listaAdmin);
            }
            listaAdmin = AdministrareFisiere::CitesteFisierAdminManga();
            listaMangauri = AdministrareFisiere::CitesteFisierReaderManga();
            go();
            _getch();
            break;
        case '5':
            Manga::ActualizareMangaReader();
            listaMangauri = AdministrareFisiere::CitesteFisierReaderManga();
            go();
            _getch();
            break;
        case 'E':
            return;
            break;
        case 'R':
            MeniuPrincipal();
        case 'X':
            exit(0);
        default:
            std::cout << (FORMAT1"\t\b\b\033[0;31mOptiune invalida\033[0m");
            Sleep(1500);
        }
    }
}



void MenuAdminInterfata()
{
    char option;
    list<Anime> listaAnimeuri = AdministrareFisiere::CitesteFisierAdminAnime();
    list<Manga> listaMangauri = AdministrareFisiere::CitesteFisierAdminManga();
    Anime nou;
    Manga nou2;
    while (1)
    {
        system("cls");
        MenuAdmin();
        switch (toupper(option = _getch()))
        {
        case '1':
            Anime::AfisareListaAnime(listaAnimeuri);
            go();
            _getch();
            break;

        case '2':
            cout << "\n\nLista totala este:\n\n";
            Anime::AfisareListaAnime(listaAnimeuri);
            nou = Anime::AdaugaAnimeAdmin();
            listaAnimeuri.push_back(nou);
            AdministrareFisiere::AdaugaAdminAnimeFisier(nou);
            listaAnimeuri = AdministrareFisiere::CitesteFisierAdminAnime();
            go();
            _getch();
            break;

        case '3':
            if (listaAnimeuri.empty() == true)
                cout << "\nLista este goala\n";
            else
            {
                Anime::ActualizareAnimeAdmin();
                listaAnimeuri = AdministrareFisiere::CitesteFisierAdminAnime();
            }
            
            go();
            _getch();
            break;

        case '4':
            Manga::AfisareListaManga(listaMangauri);
            go();
            _getch();
            break;

        case '5':
            cout << "\n\nLista totala este\n\n";
            Manga::AfisareListaManga(listaMangauri);
            nou2 = Manga::AdaugaMangaAdmin();
            listaMangauri.push_back(nou2);
            AdministrareFisiere::AdaugaAdminMangaFisier(nou2);
            listaMangauri = AdministrareFisiere::CitesteFisierAdminManga();
            go();
            _getch();
            break;

        case '6':
            if (listaMangauri.empty() == true)
            {
                cout << "\nLista este goala\n";
            }
            else
            {
                Manga::ActualizareMangaAdmin();
                listaMangauri = AdministrareFisiere::CitesteFisierAdminManga();
            }
            go();
            _getch();
            break;

        case 'R':
            return;
        case 'X':
            exit(0);
        default:
            std::cout << (FORMAT1"\t\b\b\033[0;31mOptiune invalida\033[0m");
            Sleep(1500);
        }
    }
}


#include "Anime.h"
#include "AdministrareFisiere.h"

Anime::Anime()
{
    Nume = "Nespecificat";
    SezoaneAnime = 0;
    EpisoadeAnime = 0;
    Nota = -1;
}

Anime::Anime(string nume, int  sez, int ep, double notet)
{
    Nume = nume;
    SezoaneAnime = sez;
    EpisoadeAnime = ep;
    Nota = notet;
}

Anime::~Anime()
{
    //dtor
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
bool NumeExista(string nume, list<Anime> listaAdmin)
{
    for (list<Anime>::iterator it = listaAdmin.begin(); it != listaAdmin.end(); it++)
    {
        if (nume == it->getNume())
        {
            cout << "\nNumele exista deja\n\n";
            return false;
        }
    }
    return true;
}

bool VerificaNume(string nume, list<Anime> listaAdmin)
{
    for (list<Anime>::iterator it = listaAdmin.begin(); it != listaAdmin.end(); it++)
    {
        if (nume == it->getNume())
        {
            return true;
        }
    }
    cout << "\nPoti introduce doar anime existente in lista totala\n\n";
    return false;;
}

bool VerificaSezoane(string nume, int input, list<Anime> listaAdmin)
{

    for (list<Anime>::iterator it = listaAdmin.begin(); it != listaAdmin.end(); it++)
    {
        if (nume == it->getNume())
            if (input <= it->getSezoaneAnime())
            {
                return true;
            }
    }
    cout << "\nNumarul introdus este prea mare\n\n";
    return false;
}

bool VerificaEpisoade(string nume, int input, list<Anime> listaAdmin)
{
    for (list<Anime>::iterator it = listaAdmin.begin(); it != listaAdmin.end(); it++)
    {
        if (nume == it->getNume())
            if (input <= it->getEpisoadeAnime())
            {
                return true;
            }
    }
    cout << "\nNumarul introdus este prea mare\n\n";
    return false;
}

Anime Anime::AdaugaAnime()
{
    string nume;
    int input1, input2;
    double input3;
    list<Anime> listaAdmin = AdministrareFisiere::CitesteFisierAdminAnime();
    list<Anime> listaWatcher = AdministrareFisiere::CitesteFisierWatcherAnime();
    Anime AnimeNou;
    if (listaAdmin.empty())
    {
        cout << "\nNu puteti adauga in lista personala deoarece lista totala este goala.\n";
    }
    else
    {
        do
        {
            cout << "\nIntroduceti numele animeului dorit din lista totala: ";
            cin.seekg(0, ios::end);
            cin.clear();
            getline(cin, nume);
            for (int i = 0; i < nume.length(); i++)
            {
                if (isspace(nume[i]))
                    nume[i] = '_';
            }

        } while (VerificaNume(nume, listaAdmin) == false || NumeExista(nume, listaWatcher) == false);

        do
        {
            cout << "\nIntroduceti numarul de sezoane: ";
            cin >> input1;
        } while (input1 <= 0 || VerificaSezoane(nume, input1, listaAdmin) == false);

        do
        {
            cout << "\nIntroduceti numarul de episoade: ";
            cin >> input2;
        } while (input2 < 0 || VerificaEpisoade(nume, input2, listaAdmin) == false);

        for (list<Anime>::iterator it = listaAdmin.begin(); it != listaAdmin.end(); it++)
        {
            if (nume == it->getNume())
            {
                input3 = it->getNota();
            }
        }
        


        for (auto& c : nume) c = toupper(c);

        AnimeNou.Nume = nume;
        AnimeNou.SezoaneAnime = input1;
        AnimeNou.EpisoadeAnime = input2;
        AnimeNou.Nota = input3;
    }
    return AnimeNou;
   
}

Anime Anime::AdaugaAnimeAdmin()
{
    string nume;
    int input1, input2;
    double input3;
    list<Anime> listaAdmin = AdministrareFisiere::CitesteFisierAdminAnime();
    do
    {
        cout << "\nIntroduceti numele: ";
        cin.seekg(0, ios::end);
        cin.clear();
        getline(cin, nume);
        for (int i = 0; i < nume.length(); i++)
        {
            if (isspace(nume[i]))
                nume[i] = '_';
        }
        for (auto& c : nume) c = toupper(c);
    } while (NumeExista(nume,listaAdmin)==false || nume.empty() == true);
    
    do 
    {
        cout << "\nIntroduceti numarul de sezoane: ";
        cin >> input1;
    } while (input1 <= 0);

    do
    {
        cout << "\nIntroduceti numarul de episoade: ";
        cin >> input2;
    } while (input2 < 0);
    input3 = -1;
    for (auto& c : nume) c = toupper(c);

    Anime AnimeNou(nume, input1, input2, input3);

    return AnimeNou;
}

void Anime::ActualizareAnimeWatcher()
{
    list<Anime> listaAnime = AdministrareFisiere::CitesteFisierWatcherAnime();
    list<Anime> listaAdmin = AdministrareFisiere::CitesteFisierAdminAnime();
    AfisareListaAnime(listaAnime);
    if (listaAnime.empty())
    {
        cout << "\nNu puteti actualiza deoarece lista este goala\n";
        return;
    }
    else
    {
        cout << "\nIntroduceti numele animeului pe care doriti sa il modificati: ";
        string nume;
        cin.seekg(0, ios::end);
        cin.clear();
        getline(cin, nume);
        for (int i = 0; i < nume.length(); i++)
        {
            if (isspace(nume[i]))
                nume[i] = '_';
        }
        for (auto& c : nume) c = toupper(c);
        for (list<Anime>::iterator it = listaAnime.begin(); it != listaAnime.end(); it++)
        {
            if (nume == it->getNume())
            {
                cout <<
                    (FORMAT1"|--------Meniu modificare--------|\n"
                        FORMAT1"|1-Modificati numarul de sezoane |\n"
                        FORMAT1"|2-Modificati numarul de episoade|\n"
                        FORMAT1"|3-Modificati recenzia           |\n"
                        FORMAT1"|--------------------------------|\n");
                bool select = false;
                string numeNou;
                int sezNou;
                int epNou;
                double nota;
                while (select == false)
                {
                    switch (toupper(_getch()))
                    {
                    case '1':
                        cout << "Introduceti noul numar de sezoane: ";
                        cin >> sezNou;
                        if (VerificaSezoane(nume, sezNou, listaAnime) == true)
                            it->setSezoaneAnime(sezNou);
                        else
                            cout << "\nNu s-a putut realiza modificarea.\n";
                        select = true;
                        AdministrareFisiere::RescriereFisierAnime(listaAnime);
                        break;
                    case '2':
                        cout << "Introduceti noul numar de episoade: ";
                        cin >> epNou;
                        if (VerificaEpisoade(nume, epNou, listaAnime) == true)
                            it->setEpisoadeAnime(epNou);
                        else
                            cout << "Nu s-a putut realiza modificarea.";
                        select = true;
                        AdministrareFisiere::RescriereFisierAnime(listaAnime);
                        break;
                    case '3':
                        cout << "Introduceti noua recenzie: ";
                        cin >> nota;
                        if (nota >= 0 && nota <= 10)
                            it->setNota(nota);
                        else
                            cout << "Nu s-a putut realiza modificare.";
                        select = true;
                        AdministrareFisiere::RescriereFisierAnime(listaAnime);
                        for (list<Anime>::iterator i = listaAdmin.begin(); i != listaAdmin.end(); i++)
                            if (nume == i->getNume())
                                i->setNota(nota);
                        AdministrareFisiere::RescriereFisierAdminAnime(listaAdmin);
                        break;
                    default:
                        std::cout << (FORMAT1"\t\b\b\033[0;31mOptiune invalida\033[0m");
                        Sleep(1500);
                        break;
                    }
                }

            }

        }
    }
   
}

void Anime::ActualizareAnimeAdmin()
{
    list<Anime> listaAnime = AdministrareFisiere::CitesteFisierAdminAnime();
    list<Anime> listaWatcher = AdministrareFisiere::CitesteFisierWatcherAnime();
    AfisareListaAnime(listaAnime);
    cout << "Introduceti numele animeului pe care doriti sa il modificati: ";
    string nume;
    cin.seekg(0, ios::end);
    cin.clear();
    getline(cin, nume);
    for (int i = 0; i < nume.length(); i++)
    {
        if (isspace(nume[i]))
            nume[i] = '_';
    }
    for (auto& c : nume) c = toupper(c);
    for (list<Anime>::iterator it = listaAnime.begin(); it != listaAnime.end(); it++)
    {
        if (nume == it->getNume())
        {
            cout <<
                (   FORMAT1"|--------Meniu modificare--------|\n"
                    FORMAT1"|1-Modificati numele animeului   |\n"
                    FORMAT1"|2-Modificati numarul de sezoane |\n"
                    FORMAT1"|3-Modificati numarul de episoade|\n"
                    FORMAT1"|--------------------------------|\n");
            bool select = false;
            string numeNou;
            int sezNou;
            int epNou;
            double nota;
            while (select == false)
            {
                switch (toupper(_getch()))
                {
                case '1':
                    cout << "Introduceti noul nume: ";
                    cin.seekg(0, ios::end);
                    cin.clear();
                    getline(cin, numeNou);
                    for (int i = 0; i < numeNou.length(); i++)
                    {
                        if (isspace(numeNou[i]))
                            numeNou[i] = '_';
                    }
                    for (auto& c : numeNou) c = toupper(c);
                    if (NumeExista(numeNou, listaAnime) == true)
                    {
                        it->setNume(numeNou);
                        for (list<Anime>::iterator i = listaWatcher.begin(); i != listaWatcher.end(); i++)
                            if (i->getNume() == nume)
                            {
                                i->setNume(numeNou);
                                AdministrareFisiere::RescriereFisierAnime(listaWatcher);
                            }
                    }
                            
                    select = true;
                    break;
                case '2':
                    cout << "Introduceti noul numar de sezoane: ";
                    cin >> sezNou;
                    it->setSezoaneAnime(sezNou);
                    select = true;
                    break;
                case '3':
                    cout << "Introduceti noul numar de episoade: ";
                    cin >> epNou;
                    it->setEpisoadeAnime(epNou);
                    select = true;
                    break;
                default:
                    cout << "Optiunea nu exista";
                    break;
                }
            }
            AdministrareFisiere::RescriereFisierAdminAnime(listaAnime);

        }

    }
}

void Anime::AfisareListaAnime(list<Anime> listaAnime)
{
    if (listaAnime.empty())
    {
        cout << "- GOL - ";
        return;
    }

    for (list<Anime>::iterator it = listaAnime.begin(); it != listaAnime.end(); ++it)
    {
        cout << it->ConvertToStringAnime() << "\n";
    }
}

string Anime::ConversieSirFisierAnime()
{
    return Nume + " " + to_string(SezoaneAnime) + " " + to_string(EpisoadeAnime) + " " + to_string(Nota);
}

string FaraBara(string nume)
{
    for (int i = 0; i < nume.length(); i++)
    {
        if (nume[i] == '_')
            nume[i] = ' ';
    }
    return nume;
}

string Anime::ConvertToStringAnime()
{
    std::ostringstream table;
    
    table << setw(4) << left << "Nume:" << setw(10) << left << FaraBara(Nume)
        << setw(6) << left << "Sezoane:" << setw(20) << left << SezoaneAnime
        << setw(9) << left << "Episoade:" << setw(20) << left << EpisoadeAnime
        << setw(11) << left << "Recenzie:" << setw(20) << left << Nota;
    string s = table.str();
    return s;
}


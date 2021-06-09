#include "Anime.h"
#include "AdministrareFisiere.h"

Anime::Anime()
{
    Nume = "NESPECIFICAT";
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

/////////////////////////////////////////////////////////////////////////////////////////////////////

Anime Anime::AdaugaAnime()
{
    string nume, codIntrodus;
    int input1, input2;
    input1 = -1;
    input2 = -1;
    double input3;
    list<Anime> listaAdmin = AdministrareFisiere::CitesteFisierAdminAnime();
    list<Anime> listaWatcher = AdministrareFisiere::CitesteFisierWatcherAnime();
    Anime AnimeNou;
    if (listaAdmin.empty())
    {
        cout << "\nNu puteti adauga in lista personala deoarece lista totala este goala.\n\n";
    }
    else
    {
        if (listaAdmin.size() == listaWatcher.size())
        {
            cout << "\nLista dumneavoastra este completa\n\n";
        }
        else
        {
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
            } while (VerificaNume(nume, listaAdmin) == false || NumeExista(nume, listaWatcher) == false);

            do
            {
                cout << "\nIntroduceti numarul de sezoane: ";
                cin >> codIntrodus;
                if (ValidareNumar(codIntrodus) == false)
                {
                    cout <<"\n\nNumarul a fost introdus incorect\n\n" << endl;
                    
                }
                else
                    input1 = stoi(codIntrodus);
            } while (input1 <= 0 || VerificaSezoane(nume, input1, listaAdmin) == false || ValidareNumar(codIntrodus) == false);

            do
            {
                cout << "\nIntroduceti numarul de episoade: ";
                cin >> codIntrodus;
                if (ValidareNumar(codIntrodus) == false)
                {
                    cout << "\n\nNumarul a fost introdus incorect\n\n" << endl;
                }
                else
                    input2 = stoi(codIntrodus);
            } while (input2 < 0 || VerificaEpisoade(nume, input2, listaAdmin) == false || ValidareNumar(codIntrodus) == false);

            for (list<Anime>::iterator it = listaAdmin.begin(); it != listaAdmin.end(); it++)
            {
                if (nume == it->getNume())
                {
                    input3 = it->getNota();
                }
            }

            AnimeNou.Nume = nume;
            AnimeNou.SezoaneAnime = input1;
            AnimeNou.EpisoadeAnime = input2;
            AnimeNou.Nota = input3;
        }
       
    }
    return AnimeNou;
   
}

Anime Anime::AdaugaAnimeAdmin()
{
    string nume, codIntrodus;
    int input1, input2;
    input1 = -1;
    input2 = -1;
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
        cin >> codIntrodus;
        if (ValidareNumar(codIntrodus) == false)
        {
            cout << "\n\nNumarul a fost introdus incorect\n\n" << endl;

        }
        else
            input1 = stoi(codIntrodus);
    } while (input1 <= 0 || ValidareNumar(codIntrodus) == false);

    do
    {
        cout << "\nIntroduceti numarul de episoade: ";
        cin >> codIntrodus;
        if (ValidareNumar(codIntrodus) == false)
        {
            cout << "\n\nNumarul a fost introdus incorect\n\n" << endl;
        }
        else
            input2 = stoi(codIntrodus);
    } while (input2 < 0 || ValidareNumar(codIntrodus) == false);

    input3 = -1;

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
        cout << "\nNu puteti actualiza deoarece lista este goala\n\n";
        return;
    }
    else
    {
        cout << "\nIntroduceti numele: ";
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
                cout << endl << endl;
                cout <<
                    (FORMAT1"|--------Meniu modificare--------|\n"
                        FORMAT1"|1-Modificati numarul de sezoane |\n"
                        FORMAT1"|2-Modificati numarul de episoade|\n"
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
                        cout << "\n\nIntroduceti noul numar de sezoane: ";
                        
                        cin >> numeNou;
                        if (ValidareNumar(numeNou) == false)
                        {
                            cout << "\n\nNumarul a fost introdus incorect\n" << endl;
                            select = true;
                            break;
                        }
                        sezNou = stoi(numeNou);

                        if (VerificaSezoane(nume, sezNou, listaAnime) == true && sezNou > 0)
                            it->setSezoaneAnime(sezNou);
                        else
                            cout << "\n\nNu s-a putut realiza modificarea.\n\n";
                        select = true;
                        AdministrareFisiere::RescriereFisierAnime(listaAnime);
                        break;
                    case '2':
                        cout << "\n\nIntroduceti noul numar de episoade: ";
                        
                        cin >> numeNou;
                        if (ValidareNumar(numeNou) == false)
                        {
                            cout << "\n\nNumarul a fost introdus incorect\n" << endl;
                            select = true;
                            break;
                        }
                        epNou = stoi(numeNou);

                        if (VerificaEpisoade(nume, epNou, listaAnime) == true && epNou >= 0 )
                            it->setEpisoadeAnime(epNou);
                        else
                            cout << "\n\nNu s-a putut realiza modificarea.\n\n";
                        select = true;
                        AdministrareFisiere::RescriereFisierAnime(listaAnime);
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
    cout << "\n\nIntroduceti numele: ";
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
            cout << endl << endl;
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
                    cout << "\n\nIntroduceti noul nume: ";
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
                    else
                        cout << "\n\nNu s-a putut face modificarea\n\n";              
                    select = true;
                    break;
                case '2':
                    cout << "\n\nIntroduceti noul numar de sezoane: ";
                    cin >> numeNou;
                    if (ValidareNumar(numeNou) == false)
                    {
                        cout << "\n\nNumarul a fost introdus incorect\n" << endl;
                        select = true;
                        break;
                    }
                    sezNou = stoi(numeNou);
                    if (sezNou > 0)
                        it->setSezoaneAnime(sezNou);
                    else
                        cout << "\n\nNu s-a putut face modificarea\n\n";
                    select = true;
                    break;
                case '3':
                    cout << "\n\nIntroduceti noul numar de episoade: ";
                    cin >> numeNou;
                    if (ValidareNumar(numeNou) == false)
                    {
                        cout << "\n\nNumarul a fost introdus incorect\n" << endl;
                        select = true;
                        break;
                    }
                    epNou = stoi(numeNou);
                    if( epNou >= 0)
                        it->setEpisoadeAnime(epNou);
                    else
                        cout << "\n\nNu s-a putut face modificarea\n\n";
                    select = true;
                    break;
                default:
                    std::cout << (FORMAT1"\t\b\b\033[0;31mOptiune invalida\033[0m");
                    Sleep(1500);
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
    
    table << setw(4) << left << "Nume:" << setw(20) << left << FaraBara(Nume)
        << setw(6) << left << "Sezoane:" << setw(10) << left << SezoaneAnime
        << setw(6) << left << "Episoade:" << setw(10) << left << EpisoadeAnime
        << setw(6) << left << "Recenzie:" << setw(10) << left << Nota;
    string s = table.str();
    return s;
}


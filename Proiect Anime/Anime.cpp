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

bool VerificaSezoane(int input, list<Anime> listaAdmin)
{

    for (list<Anime>::iterator it = listaAdmin.begin(); it != listaAdmin.end(); it++)
    {
        if (input == it->getSezoaneAnime())
        {
            return true;
        }
    }
    cout << "\nNumarul introdus este prea mare\n\n";
    return false;
}

bool VerificaEpisoade(int input, list<Anime> listaAdmin)
{
    for (list<Anime>::iterator it = listaAdmin.begin(); it != listaAdmin.end(); it++)
    {
        if (input == it->getEpisoadeAnime())
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
    do
    {
        cout << "\nIntroduceti numele animeului dorit din lista totala: ";
        cin >> nume;
       
    } while (VerificaNume(nume,listaAdmin)==false);

    do
    {
        cout << "\nIntroduceti numarul de sezoane: ";
        cin >> input1;
    } while (input1 <= 0 && VerificaSezoane(input1,listaAdmin)==false);

    do
    {
        cout << "\nIntroduceti numarul de episoade: ";
        cin >> input2;
    } while (input2 < 0 && VerificaEpisoade(input2,listaAdmin)==false);

    do
    {
        cout << "\nIntroduceti o recenzie: ";
        cin >> input3;
    } while (input3 < 0 || input3 > 10);


    for (auto& c : nume) c = toupper(c);

    Anime AnimeNou(nume, input1, input2, input3);

    return AnimeNou;
}

Anime Anime::AdaugaAnimeAdmin()
{
    string nume;
    int input1, input2;
    double input3;
    do
    {
        cout << "\nIntroduceti numele: ";
        cin >> nume;
    } while (!ValidareString(nume));

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
    AfisareListaAnime(listaAnime);
    cout << "\nIntroduceti numele mangaului pe care doriti sa o modificati: ";
    string nume;
    cin >> nume;

    for (list<Anime>::iterator it = listaAnime.begin(); it != listaAnime.end(); it++)
    {
        if (nume == it->getNume())
        {
            cout <<
                (FORMAT1"|--------Meniu modificare-------|\n"
                 FORMAT1"|1-Modificati numarul de sezoane|\n"
                 FORMAT1"|2-Modificati numarul de episoade|\n"
                 FORMAT1"|3-Modificati recenzia          |\n"
                 FORMAT1"|-------------------------------|\n");
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
                    it->setSezoaneAnime(sezNou);
                    select = true;
                    AdministrareFisiere::RescriereFisierAnime(listaAnime);
                    break;
                case '2':
                    cout << "Introduceti noul numar de episoade: ";
                    cin >> epNou;
                    it->setEpisoadeAnime(epNou);
                    select = true;
                    AdministrareFisiere::RescriereFisierAnime(listaAnime);
                    break;
                case '3':
                    cout << "Introduceti noua recenzie: ";
                    cin >> nota;
                    it->setNota(nota);
                    select = true;
                    AdministrareFisiere::RescriereFisierAdminAnime(listaAnime);
                    break;
                default:
                    cout << "Optiunea nu exista";
                    break;
                }
            }
            
        }

    }
}

void Anime::ActualizareAnimeAdmin()
{
    list<Anime> listaAnime = AdministrareFisiere::CitesteFisierAdminAnime();
    AfisareListaAnime(listaAnime);
    cout << "Introduceti numele animeului pe care doriti sa o modificati: ";
    string nume;
    cin >> nume;

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
                    cin >> numeNou;
                    it->setNume(numeNou);
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

string Anime::ConvertToStringAnime()
{
    std::ostringstream table;
    table << setw(4) << left << "Nume:" << setw(10) << left << Nume
        << setw(6) << left << "Sezoane:" << setw(20) << left << SezoaneAnime
        << setw(9) << left << "Episoade:" << setw(20) << left << EpisoadeAnime
        << setw(11) << left << "Recenzie:" << setw(20) << left << Nota;
    //return "ID: " + to_string(cod) + " \t Nume: " + nume + " \t Prenume: " + prenume + " \t Abonament: " + tipAbonament;
    string s = table.str();
    return s;
}


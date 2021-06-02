#include "AdministrareFisiere.h"
#include "Manga.h"

Manga::Manga()
{
    Nume = "Nespecificat";
    VolumeManga = 0;
    CapitoleManga = 0;
    Nota = -1;
}

Manga::Manga(string nume, int  sez, int ep, double notet)
{
    Nume = nume;
    VolumeManga= sez;
    CapitoleManga = ep;
    Nota = notet;
}

Manga::~Manga()
{
    //dtor
}
//////////////////////////////////////////////////////////////////////////////////

bool VerificaNume(string nume, list<Manga> listaAdmin)
{
    for (list<Manga>::iterator it = listaAdmin.begin(); it != listaAdmin.end(); it++)
    {
        if (nume == it->getNume())
        {
            return true;
        }
    }
    cout << "\nPoti introduce doar mangauri existente in lista totala\n\n";
    return false;;
}

bool VerificaSezoane(int input, list<Manga> listaAdmin)
{

    for (list<Manga>::iterator it = listaAdmin.begin(); it != listaAdmin.end(); it++)
    {
        if (input == it->getVolumeManga())
        {
            return true;
        }
    }
    cout << "\nNumarul introdus este prea mare\n\n";
    return false;
}

bool VerificaEpisoade(int input, list<Manga> listaAdmin)
{
    for (list<Manga>::iterator it = listaAdmin.begin(); it != listaAdmin.end(); it++)
    {
        if (input == it->getCapitoleManga())
        {
            return true;
        }
    }
    cout << "\nNumarul introdus este prea mare\n\n";
    return false;
}

Manga Manga::AdaugaManga()
{
    string nume;
    int input1, input2;
    double input3;
    list<Manga> listaAdmin = AdministrareFisiere::CitesteFisierAdminManga();
    do
    {
        cout << "\nIntroduceti numele: ";
        cin >> nume;
    } while (VerificaNume(nume,listaAdmin)==false);

    do
    {
        cout << "\nIntroduceti numarul de volume: ";
        cin >> input1;
    } while (input1 <= 0 && VerificaSezoane(input1, listaAdmin) == false);

    do
    {
        cout << "\nIntroduceti numarul de capitole: ";
        cin >> input2;
    } while (input2 < 0 && VerificaEpisoade(input2,listaAdmin)==false);

    do
    {
        cout << "\nIntroduceti o recenzie: ";
        cin >> input3;
    } while (input3 < 0 || input3 > 10);


    for (auto& c : nume) c = toupper(c);

    Manga MangaNou(nume, input1, input2, input3);

    return MangaNou;
}

Manga Manga::AdaugaMangaAdmin()
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
        cout << "\nIntroduceti numarul de volume: ";
        cin >> input1;
    } while (input1 <= 0);

    do
    {
        cout << "\nIntroduceti numarul de capitole: ";
        cin >> input2;
    } while (input2 < 0);

    input3 = -1;

    for (auto& c : nume) c = toupper(c);

    Manga MangaNou(nume, input1, input2, input3);

    return MangaNou;
}

void Manga::ActualizareMangaReader()
{
    list<Manga> listaManga = AdministrareFisiere::CitesteFisierReaderManga();
    AfisareListaManga(listaManga);
    cout << "Introduceti numele mangaului pe care doriti sa o modificati: ";
    string nume;
    cin >> nume;

    for (list<Manga>::iterator it = listaManga.begin(); it != listaManga.end(); it++)
    {
        if (nume == it->getNume())
        {

            cout <<
                (FORMAT1"|--------Meniu modificare-------|\n"
                    FORMAT1"|1-Modificati numarul de volume |\n"
                    FORMAT1"|2-Modificati numarul de capitole|\n"
                    FORMAT1"|3-Modificati recenzia          |\n"
                    FORMAT1"|-------------------------------|\n");
            bool select = false;
            string numeNou;
            int volNou;
            int capNou;
            double nota;
            while (select == false)
            {
                switch (toupper(_getch()))
                {

                case '1':
                    cout << "Introduceti noul numar de volume: ";
                    cin >> volNou;
                    it->setVolumeManga(volNou);
                    select = true;
                    AdministrareFisiere::RescriereFisierManga(listaManga);
                    break;
                case '2': 
                    cout << "Introduceti noul numar de capitole: ";
                    cin >> capNou;
                    it->setCapitoleManga(capNou);
                    select = true;
                    AdministrareFisiere::RescriereFisierManga(listaManga);
                    break;
                case '3':
                    cout << "Introduceti noua recenzie: ";
                    cin >> nota;
                    it->setNota(nota);
                    select = true;
                    AdministrareFisiere::RescriereFisierAdminManga(listaManga);
                    break;
                default:
                    cout << "Optiunea nu exista";
                    break;
                }
            }
            AdministrareFisiere::RescriereFisierManga(listaManga);
        }

    }
}

void Manga::ActualizareMangaAdmin()
{
    list<Manga> listaManga = AdministrareFisiere::CitesteFisierAdminManga();
    AfisareListaManga(listaManga);
    cout << "Introduceti numele mangaului pe care doriti sa o modificati: ";
    string nume;
    cin >> nume;

    for (list<Manga>::iterator it = listaManga.begin(); it != listaManga.end(); it++)
    {
        if (nume == it->getNume())
        {
            cout <<
                (FORMAT1"|--------Meniu modificare--------|\n"
                    FORMAT1"|1-Modificati numele mangaului   |\n"
                    FORMAT1"|2-Modificati numarul de volume  |\n"
                    FORMAT1"|3-Modificati numarul de capitole|\n"
                    FORMAT1"|--------------------------------|\n");
            bool select = false;
            string numeNou;
            int volNou;
            int capNou;
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
                    cout << "Introduceti noul numar de volume: ";
                    cin >> volNou;
                    it->setVolumeManga(volNou);
                    select = true;
                    break;
                case '3':
                    cout << "Introduceti noul numar de capitole: ";
                    cin >> capNou;
                    it->setCapitoleManga(capNou);
                    select = true;
                    break;

                default:
                    cout << "Optiunea nu exista";
                    break;
                }
            }
            AdministrareFisiere::RescriereFisierAdminManga(listaManga);

        }

    }
}

void Manga::AfisareListaManga(list<Manga> listaManga)
{
    if (listaManga.empty())
    {
        cout << "- GOL - ";
        return;
    }

    for (list<Manga>::iterator it = listaManga.begin(); it != listaManga.end(); ++it)
    {
        cout << it->ConvertToStringManga() << "\n";
    }
}

string Manga::ConversieSirFisierManga()
{
    return Nume + " " + to_string(VolumeManga) + " " + to_string(CapitoleManga) + " " + to_string(Nota);
}

string Manga::ConvertToStringManga()
{
    std::ostringstream table;
    table << setw(4) << left << "Nume:" << setw(10) << left << Nume
        << setw(6) << left << "Volume:" << setw(20) << left << VolumeManga
        << setw(9) << left << "Capitole:" << setw(20) << left << CapitoleManga
        << setw(11) << left << "Recenzie:" << setw(20) << left << Nota;
    string s = table.str();
    return s;
}

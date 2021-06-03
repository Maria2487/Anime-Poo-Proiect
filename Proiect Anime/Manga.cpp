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
bool NumeExista(string nume, list<Manga> listaAdmin)
{
    for (list<Manga>::iterator it = listaAdmin.begin(); it != listaAdmin.end(); it++)
    {
        if (nume == it->getNume())
        {
            cout << "\nNumele exista deja\n\n";
            return false;
        }
    }
    
    return true;
}

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

bool VerificaSezoane(string nume,int input, list<Manga> listaAdmin)
{

    for (list<Manga>::iterator it = listaAdmin.begin(); it != listaAdmin.end(); it++)
    {
        if (nume == it->getNume())
            if (input <= it->getVolumeManga())
            {
                return true;
            }
    }
    cout << "\nNumarul introdus este prea mare\n\n";
    return false;
}

bool VerificaEpisoade(string nume,int input, list<Manga> listaAdmin)
{
    for (list<Manga>::iterator it = listaAdmin.begin(); it != listaAdmin.end(); it++)
    {
        if (nume == it->getNume())
            if (input <= it->getCapitoleManga())
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
    list<Manga> listaManga = AdministrareFisiere::CitesteFisierReaderManga();
    do
    {
        cout << "\nIntroduceti numele: ";
        cin >> nume;
    } while (VerificaNume(nume,listaAdmin)==false || NumeExista(nume,listaManga)==false);

    do
    {
        cout << "\nIntroduceti numarul de volume: ";
        cin >> input1;
    } while (input1 <= 0 || VerificaSezoane(nume,input1, listaAdmin) == false);

    do
    {
        cout << "\nIntroduceti numarul de capitole: ";
        cin >> input2;
    } while (input2 < 0 || VerificaEpisoade(nume,input2,listaAdmin)==false);

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
    list<Manga> listaAdmin = AdministrareFisiere::CitesteFisierAdminManga();
    do 
    {
        cout << "\nIntroduceti numele: ";
        cin >> nume;
    } while (NumeExista(nume,listaAdmin)==false);
    
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
    list<Manga> listaAdmin = AdministrareFisiere::CitesteFisierAdminManga();
    AfisareListaManga(listaManga);
    cout << "Introduceti numele mangaului pe care doriti sa o modificati: ";
    string nume;
    cin >> nume;

    for (list<Manga>::iterator it = listaManga.begin(); it != listaManga.end(); it++)
    {
        if (nume == it->getNume())
        {

            cout <<
                (
                    FORMAT1"|--------Meniu modificare--------|\n"
                    FORMAT1"|1-Modificati numarul de volume  |\n"
                    FORMAT1"|2-Modificati numarul de capitole|\n"
                    FORMAT1"|3-Modificati recenzia           |\n"
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
                    cout << "Introduceti noul numar de volume: ";
                    cin >> volNou;
                    if(VerificaSezoane(nume,volNou,listaManga)==true)
                        it->setVolumeManga(volNou);
                    else
                        cout << "\nNu s-a putut realiza modificarea.\n";
                    select = true;
                    AdministrareFisiere::RescriereFisierManga(listaManga);
                    break;
                case '2': 
                    cout << "Introduceti noul numar de capitole: ";
                    cin >> capNou;
                    if(VerificaEpisoade(nume,capNou,listaManga)==true)
                        it->setCapitoleManga(capNou);
                    else
                        cout << "\nNu s-a putut realiza modificarea.\n";
                    select = true;
                    AdministrareFisiere::RescriereFisierManga(listaManga);
                    break;
                case '3':
                    cout << "Introduceti noua recenzie: ";
                    cin >> nota;
                    if (nota >= 0 && nota <= 10)
                        it->setNota(nota);
                    else
                        cout << "Nu s-a putut realiza modificare.";
                    select = true;
                    AdministrareFisiere::RescriereFisierManga(listaManga);
                    for (list<Manga>::iterator i = listaAdmin.begin(); i != listaAdmin.end(); i++)
                        if (nume == i->getNume())
                            i->setNota(nota);
                    AdministrareFisiere::RescriereFisierAdminManga(listaAdmin);
                    break;
                default:
                    std::cout << (FORMAT1"\t\b\b\033[0;31mOptiune invalida\033[0m");
                    Sleep(1500);
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
    list<Manga> listaReader = AdministrareFisiere::CitesteFisierReaderManga();
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
                    if (NumeExista(numeNou, listaManga) == true)
                    {
                        it->setNume(numeNou);
                        for (list<Manga>::iterator i = listaReader.begin(); i != listaReader.end(); i++)
                            if (i->getNume() == nume)
                            {
                                i->setNume(numeNou);
                                AdministrareFisiere::RescriereFisierManga(listaReader);
                            }
                    }
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
                    std::cout << (FORMAT1"\t\b\b\033[0;31mOptiune invalida\033[0m");
                    Sleep(1500);
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

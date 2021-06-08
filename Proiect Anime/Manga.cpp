#include "AdministrareFisiere.h"
#include "Manga.h"

Manga::Manga()
{
    Nume = "NESPECIFICAT";
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
    Manga MangaNou;
    if (listaAdmin.empty())
    {
        cout << "\nNu puteti adauga in lista personala deoarece lista totala este goala\n\n";
    }
    else
    {
        if (listaAdmin.size() == listaManga.size())
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
            } while (VerificaNume(nume, listaAdmin) == false || NumeExista(nume, listaManga) == false);

            do
            {
                cout << "\nIntroduceti numarul de volume: ";
                cin >> input1;
            } while (input1 <= 0 || VerificaSezoane(nume, input1, listaAdmin) == false);

            do
            {
                cout << "\nIntroduceti numarul de capitole: ";
                cin >> input2;
            } while (input2 < 0 || VerificaEpisoade(nume, input2, listaAdmin) == false);

            for (list<Manga>::iterator it = listaAdmin.begin(); it != listaAdmin.end(); it++)
            {
                if (nume == it->getNume())
                {
                    input3 = it->getNota();
                }
            }

            MangaNou.Nume = nume;
            MangaNou.VolumeManga = input1;
            MangaNou.CapitoleManga = input2;
            MangaNou.Nota = input3;
        }
    }
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
        cout << "\nIntroduceti numarul de volume: ";
        cin >> input1;
    } while (input1 <= 0);

    do
    {
        cout << "\nIntroduceti numarul de capitole: ";
        cin >> input2;
    } while (input2 <= 0);

    input3 = -1;

    Manga MangaNou(nume, input1, input2, input3);

    return MangaNou;
}

void Manga::ActualizareMangaReader()
{
    list<Manga> listaManga = AdministrareFisiere::CitesteFisierReaderManga();
    list<Manga> listaAdmin = AdministrareFisiere::CitesteFisierAdminManga();
    AfisareListaManga(listaManga);
    if (listaManga.empty())
    {
        cout << "\nNu puteti actualiza deoarece lista este goala\n\n";
        return;
    }
    else
    {
        cout << "Introduceti numele: ";
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

        for (list<Manga>::iterator it = listaManga.begin(); it != listaManga.end(); it++)
        {
            if (nume == it->getNume())
            {
                cout << endl << endl;
                cout <<
                    (
                        FORMAT1"|--------Meniu modificare--------|\n"
                        FORMAT1"|1-Modificati numarul de volume  |\n"
                        FORMAT1"|2-Modificati numarul de capitole|\n"
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
                        cout << "\n\nIntroduceti noul numar de volume: ";
                        cin >> volNou;
                        if (VerificaSezoane(nume, volNou, listaManga) == true && volNou > 0)
                            it->setVolumeManga(volNou);
                        else
                            cout << "\n\nNu s-a putut realiza modificarea.\n\n";
                        select = true;
                        AdministrareFisiere::RescriereFisierManga(listaManga);
                        break;
                    case '2':
                        cout << "\n\nIntroduceti noul numar de capitole: ";
                        cin >> capNou;
                        if (VerificaEpisoade(nume, capNou, listaManga) == true && capNou >= 0)
                            it->setCapitoleManga(capNou);
                        else
                            cout << "\\nnNu s-a putut realiza modificarea.\n\n";
                        select = true;
                        AdministrareFisiere::RescriereFisierManga(listaManga);
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
}

void Manga::ActualizareMangaAdmin()
{
    list<Manga> listaManga = AdministrareFisiere::CitesteFisierAdminManga();
    list<Manga> listaReader = AdministrareFisiere::CitesteFisierReaderManga();
    AfisareListaManga(listaManga);
    cout << "Introduceti numele: ";
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
    for (list<Manga>::iterator it = listaManga.begin(); it != listaManga.end(); it++)
    {
        if (nume == it->getNume())
        {
            cout << endl << endl;
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
                    cout << "\n\nIntroduceti noul nume: \n\n";
                    cin.seekg(0, ios::end);
                    cin.clear();
                    getline(cin, numeNou);
                    for (int i = 0; i < numeNou.length(); i++)
                    {
                        if (isspace(numeNou[i]))
                            numeNou[i] = '_';
                    }
                    for (auto& c : numeNou) c = toupper(c);
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
                    else
                        cout << "\n\nNu s-a putut face modificarea\n\n";
                    select = true;
                    break;
                case '2':
                    cout << "\n\nIntroduceti noul numar de volume: ";
                    cin >> volNou;
                    if(volNou > 0)
                        it->setVolumeManga(volNou);
                    else
                        cout << "\n\nNu s-a putut face modificarea\n\n";
                    select = true;
                    break;
                case '3':
                    cout << "\n\nIntroduceti noul numar de capitole: ";
                    cin >> capNou;
                    if(capNou >= 0)
                        it->setCapitoleManga(capNou);
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
    table << setw(4) << left << "Nume:" << setw(20) << left << FaraBara(Nume)
        << setw(6) << left << "Volume:" << setw(10) << left << VolumeManga
        << setw(6) << left << "Capitole:" << setw(10) << left << CapitoleManga
        << setw(6) << left << "Recenzie:" << setw(10) << left << Nota;
    string s = table.str();
    return s;
}
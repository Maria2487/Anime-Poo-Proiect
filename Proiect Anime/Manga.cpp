#include "Manga.h"
Manga::Manga()
{
    VolumeManga = 0;
    CapitoleManga = 0;
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

Manga Manga::AdaugaManga()
{
    string nume;
    int input1, input2;
    double input3;
    do
    {
        cout << FORMAT1"Introduceti numele: ";
        cin >> nume;
    } while (!ValidareString(nume));
    cin.seekg(0, ios::end);//in caz ca sunt introduse 2 cuvinte
    cin.clear();
    do
    {
        cout << "Introduceti numarul de sezoane: ";
        cin >> input1;
    } while (input1 <= 0);

    do
    {
        cout << "Introduceti numarul de episoade: ";
        cin >> input2;
    } while (input2 < 0);

    do
    {
        cout << "Introduceti o recenzie: ";
        cin >> input3;
    } while (input3 < 0 || input3 > 10);


    for (auto& c : nume) c = toupper(c);

    Manga MangaNou(nume, input1, input2, input3);

    return MangaNou;
}

Manga Manga::ActualizareManga()
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
            cout << "Meniu modificare";
            cout << "1-Modificati numele";
            cout << "2-Modificati numarul de volume";
            cout << "3-Modifiati numarul de capitole";
            cout << "4-Modificati recenzia";
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
                case '4':
                    cout << "Introduceti noua recenzie: ";
                    cin >> nota;
                    it->setNota(nota);
                    select = true;
                    break;
                default:
                    cout << "Optiunea nu exista";
                    break;
                }
            }
            AdministrareFisiere::RescriereFisierManga(listaManga);
            return;
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
    table << setw(4) << left << "ID:" << setw(10) << left << Nume
        << setw(6) << left << "Nume:" << setw(20) << left << VolumeManga
        << setw(9) << left << "Prenume:" << setw(20) << left << CapitoleManga
        << setw(11) << left << "Abonament:" << setw(20) << left << Nota;
    string s = table.str();
    return s;
}

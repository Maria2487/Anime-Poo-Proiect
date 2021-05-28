#include "Anime.h"

Anime::Anime()
{
    SezoaneAnime = 0;
    EpisoadeAnime = 0;
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

Anime Anime::AdaugaAnime()
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

    Anime AnimeNou(nume, input1, input2, input3);

    return AnimeNou;
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
    table << setw(4) << left << "ID:" << setw(10) << left << Nume
        << setw(6) << left << "Nume:" << setw(20) << left << SezoaneAnime
        << setw(9) << left << "Prenume:" << setw(20) << left << EpisoadeAnime
        << setw(11) << left << "Abonament:" << setw(20) << left << Nota;
    //return "ID: " + to_string(cod) + " \t Nume: " + nume + " \t Prenume: " + prenume + " \t Abonament: " + tipAbonament;
    string s = table.str();
    return s;
}


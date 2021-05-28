#include "Anime.h"

Anime::Anime()
{
    //ctor
}

void Anime::ScriereInFisierAnime()
{
}

list<Anime> Anime::CitireDinFisierAnime()
{
    return list<Anime>();
}
void Anime::AfisareAnime()
{

}

list<Anime> Anime::CitireAnime()
{
    return list<Anime>();
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

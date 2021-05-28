#include "Manga.h"
#include "The High Ground.h"
Manga::Manga()
{
    //ctor
}

void Manga::ScriereInFisierManga()
{
}

list<Manga> Manga::CitireDinFisierManga()
{
    return list<Manga>();
}
void Manga::AfisareManga()
{

}



list<Manga> Manga::CitireManga()
{
    return list<Manga>;
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

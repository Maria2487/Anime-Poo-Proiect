#pragma once
#include "The High Ground.h"
#include "MyAnimeList.h"
class Manga : public MyAnimeList
{

private:
    int VolumeManga;
    int CapitoleManga;

public:
    Manga();
    Manga(string nume, int sez, int ep, double notet);

    virtual ~Manga();
    ///////////////////////////////////////////////////////

    void setVolumeManga(int s)
    {
        VolumeManga = s;
    }

    int getVolumeManga()
    {
        return VolumeManga;
    }
    void setCapitoleManga(int e)
    {
        CapitoleManga = e;
    }

    int getCapitoleManga()
    {
        return CapitoleManga;
    }

    //////////////////////////////////////////////////////////////////
    list<Manga> CitireManga();
    void AfisareManga();
    void ScriereInFisierManga();
    list<Manga> CitireDinFisierManga();

};


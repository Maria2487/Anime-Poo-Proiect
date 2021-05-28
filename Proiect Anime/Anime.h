#pragma once
#include "The High Ground.h"
#include "MyAnimeList.h"

class Anime : public MyAnimeList
{
private:
    int SezoaneAnime;
    int EpisoadeAnime;

public:
    Anime();
    Anime(string nume, int sez, int ep, double notet);

    virtual ~Anime();
    ///////////////////////////////////////////////////////

    void setSezoaneAnime(int s)
    {
        SezoaneAnime = s;
    }

    int getSezoaneAnime()
    {
        return SezoaneAnime;
    }
    void setEpisoadeAnime(int e)
    {
        EpisoadeAnime = e;
    }

    int getEpisoadeAnime()
    {
        return EpisoadeAnime;
    }

    //////////////////////////////////////////////////////////////////
    list<Anime> CitireAnime();
    void AfisareAnime();
    void ScriereInFisierAnime();
    list<Anime> CitireDinFisierAnime();

};


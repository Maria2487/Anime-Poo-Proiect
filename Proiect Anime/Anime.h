#ifndef Anime_H
#define Anime_H
#pragma once
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
    static Anime AdaugaAnime();
    static Anime AdaugaAnimeAdmin();
    static void ActualizareAnimeWatcher();
    static void ActualizareAnimeAdmin();
    static void AfisareListaAnime(list<Anime> listaAnime);
    string ConvertToStringAnime();
    string ConversieSirFisierAnime();
};

#endif



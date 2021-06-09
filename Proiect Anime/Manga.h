#ifndef Manga_H
#define Manga_H
#pragma once
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
    static Manga AdaugaManga();
    static Manga AdaugaMangaAdmin();
    static void ActualizareMangaAdmin();
    static void ActualizareMangaReader();
    static void AfisareListaManga(list<Manga> listaManga);
    string ConvertToStringManga();
    string ConversieSirFisierManga();

};

#endif


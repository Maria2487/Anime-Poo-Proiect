#ifndef MyAnimeList_H
#define MyAnimeList_H
#pragma once
#include "The High Ground.h"
class MyAnimeList
{
protected:
	string Nume;
	double Nota = 0;

public:
    void setNume(string num)
    {
        Nume = num;
    }

    string getNume()
    {
        return Nume;
    }

    void setNota(double n)
    {
        Nota = n;
    }

    double getNota()
    {
        return Nota;
    }
};

#endif


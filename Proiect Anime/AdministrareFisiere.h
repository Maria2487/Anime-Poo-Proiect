#ifndef AdministrareFisiere_H
#define AdministrareFisiere_H

#pragma once
#include "The High Ground.h"
#include "Anime.h"
#include "Manga.h"

class AdministrareFisiere
{
private:
	static string numeFisierWatcher;
	static string numeFisierReader;
	static string numeFisierAdminAnime;
	static string numeFisierAdminManga;
public:
	static void AdaugaWatcherFisier(Anime a);
	static void AdaugaReaderFisier(Manga m);
	static void AdaugaAdminAnimeFisier(Anime a);
	static void AdaugaAdminMangaFisier(Manga m);

	static list<Anime> CitesteFisierWatcherAnime();
	static list<Manga> CitesteFisierReaderManga();
	static list<Anime> CitesteFisierAdminAnime();
	static list<Manga> CitesteFisierAdminManga();


	static void RescriereFisierAnime(list<Anime> listaAnime);
	static void RescriereFisierManga(list<Manga> listaManga);
	static void RescriereFisierAdminAnime(list<Anime> listaAnime);
	static void RescriereFisierAdminManga(list<Manga> listaManga);
};

#endif
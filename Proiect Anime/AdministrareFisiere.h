#pragma once
#include "The High Ground.h"
#include "Anime.h"
#include "Manga.h"
class AdministrareFisiere
{
private:
	static string numeFisierWatcher;
	static string numeFisierReader;
	static string numeFisierAdmin;
public:
	static void AdaugaWatcherFisier(Anime a);
	static void AdaugaReaderFisier(Manga m);
	static void AdaugaAdminFisier();

	static list<Anime> CitesteFisierWatcherAnime();
	static list<Manga> CitesteFisierReaderManga();
	static void CitesteFisierAdmin();
};


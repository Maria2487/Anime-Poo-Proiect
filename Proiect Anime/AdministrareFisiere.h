#pragma once
#include "The High Ground.h"
#include "Anime.h"
#include "Manga.h"
class AdministrareFisiere
{
private:
	static string numeFisierWatcher;
	static string numeFisierAdmin;
public:
	static void AdaugaWatcherFisier(Anime a);
	static void AdaugaAdminFisier();

	static list<Anime> CitesteFisierWatcherAnime();
	//static list<Manga> CitesteFisierWatcherAnime(Manga);
	static void CitesteFisierAdmin();
};


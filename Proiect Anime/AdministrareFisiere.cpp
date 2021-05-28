#include "AdministrareFisiere.h"

string AdministrareFisiere::numeFisierWatcher = "Watcher.txt";
string AdministrareFisiere::numeFisierAdmin = "Admin.txt";

void AdministrareFisiere::AdaugaWatcherFisier(Anime a)
{
	ofstream f;
	f.open(numeFisierWatcher, std::ios_base::app);

	if (f.fail())
	{
		cout << "Fisierul nu a putut fi deschis.";
		return;
	}
	else
		f << a.ConversieSirFisier() << endl;
	f.close();
}

list<Anime> AdministrareFisiere::CitesteFisierWatcherAnime()
{
	ifstream f;
	f.open(numeFisierWatcher);
	string line_info, input_result;
	vector<string> vectorString;
	list<Anime> listaAnime;
	if (!f.fail()) // has the file
	{
		while (getline(f, line_info)) // line breaks are not included in the line
		{
			stringstream input(line_info);
			while (input >> input_result)
				vectorString.push_back(input_result);

			Anime newAnime;
			newAnime.setNume(vectorString[0]);
			newAnime.setSezoaneAnime(stoi(vectorString[1]));
			newAnime.setEpisoadeAnime(stoi(vectorString[2]));
			newAnime.setNota(stod(vectorString[3]));
			listaAnime.push_back(newAnime);

			for (int j = 0; j < vectorString.size(); j++)
			{
				vectorString.clear();
			}
		}
		f.close();
	}
	else // no such file
	{
		cout << "Eroare la deschiderea fisierului" << endl;
	}
	return listaAnime;
}

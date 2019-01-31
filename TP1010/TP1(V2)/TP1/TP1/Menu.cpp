#include "Menu.h"
#include <fstream>

Menu::Menu() : capacite_(MAXPLAT), nbPlats_(0), type_(Matin)
{
	listePlats_ = new Plat*[capacite_];
}

Menu::Menu(string fichier, TypeMenu type) : capacite_(MAXPLAT), nbPlats_(0), type_(type)
{
	listePlats_ = new Plat*[capacite_];
	lireMenu(fichier);
	
}

Menu::~Menu() { //Destructeur

	for (int i = 0; i < nbPlats_; i++) {
		listePlats_[i] = nullptr;
	}		
	delete[] listePlats_;
}

int Menu::getNbPlats() const
{
	return nbPlats_;
}

void Menu::afficher() const
{
	for (unsigned int i = 0; i < nbPlats_; i++) {
		{
			listePlats_[i]->afficher;
		}
	}
}

Plat * Menu::trouverPlat(string & nom)
{
	for (unsigned int i = 0; i < nbPlats_; i++) {
		if (nom == listePlats_[i]->getNom()) {
			return listePlats_[i];
		}
	}
	return nullptr;
}

void Menu::ajouterPlat(Plat & plat)
{
	Plat* pointeurPlat;
	*pointeurPlat = plat;
	listePlats_[nbPlats_] = pointeurPlat;
	nbPlats_++;
}

void Menu::ajouterPlat(string & nom, double montant, double cout)
{
	Plat* pointeurPlat;
	Plat plat(nom, montant, cout);
	*pointeurPlat = plat;
	listePlats_[nbPlats_] = pointeurPlat;
}

bool Menu::lireMenu(string & fichier)
{
	ifstream liste("test.txt", ios::in);
	string ligneLu;
	bool finit = false;
	while (!ws(liste).eof())
	{
		getline(liste, ligneLu);
		if ((ligneLu == "-MATIN" && type_ == Matin) || (ligneLu == "-MIDI" && type_ == Midi) || (ligneLu == "-SOIR" && type_ == Soir)) 
		{
			while (!ws(liste).eof() && !finit)
			{
				string nomPlat;
				liste >> nomPlat;
				if (nomPlat[0] == '-') 
				{
						finit = 1;
						break;
				}
								
				double prix;
				double cout;
				liste >> prix >> cout;
				ajouterPlat(nomPlat, prix, cout);
			}
		}
	}
	return false;
}

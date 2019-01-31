#include "Table.h"
#include <fstream>

Table::Table()
{
	capacite_ = MAXCAP;
	id_ = -1;
	nbPlats_ = 0;
	nbPlaces_ = 1;
	occupee_ = false;
	commande_ = new Plat*[MAXCAP];
}

Table::Table(int id, int nbPlaces)
{
	capacite_ = MAXCAP;
	id_ = id;
	nbPlats_ = 0;
	nbPlaces_ = nbPlaces;
	occupee_ = false;
	commande_ = new Plat*[MAXCAP];

}

int Table::getId()
{
	return id_;
}

int Table::getNbPlaces()
{
	return nbPlaces_;
}

bool Table::estOccupee()
{
	return occupee_;
}

void Table::libererTable()
{
	occupee_ == false;

	for  (int i = 0; i < nbPlaces_; i++)
	{
		commande_[i] = nullptr;
	}
}

void Table::placerClient()
{
	occupee_ == true;
}

void Table::setId(int id)
{
	id_ = id;
}

void Table::commander(Plat * plat)
{
	commande_[nbPlats_] = plat;
	nbPlats_++;
}

double Table::getChiffreAffaire()
{
	double prix = 0.0;

	for (int i = 0; i < nbPlaces_; i++)
	{
		prix += commande_[i]->getPrix;
	}
	return prix;
}

void Table::afficher()
{
	cout << "La table numero " << id_ << " est ";
	if (occupee_) {
		cout << "occupe. Voici les commandes passees par les clients :" << endl;
		for (int i = 0; i < nbPlaces_; i++)
		{
			commande_[i]->afficher;
		}
	}
	else
		cout << "libre." << endl;
}

#include "Table.h"
#include <fstream>

Table::Table() : capacite_(MAXCAP), id_(-1), nbPlaces_(1), occupee_(false), nbPlats_(0)
{
	commande_ = new Plat*[MAXCAP];
}

Table::Table(int id, int nbPlaces) : capacite_(MAXCAP), id_(id), nbPlaces_(nbPlaces), occupee_(false), nbPlats_(0)
{
	commande_ = new Plat*[MAXCAP];
	
}

Table::~Table() {
	for (int i = 0; i < nbPlats_; i++) {
		commande_[i] = nullptr;
	}
	delete[] commande_;
}

int Table::getId() const
{
	return id_;
}

int Table::getNbPlaces() const
{
	return nbPlaces_;
}

bool Table::estOccupee() const
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

	for (int i = 0; i < nbPlats_; i++)
	{
		prix += commande_[i]->getPrix;
	}
	return prix;
}

void Table::afficher() const
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

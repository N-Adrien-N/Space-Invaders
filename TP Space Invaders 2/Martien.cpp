#include "Martien.h"
#include <random>
Martien::Martien(Coord coord, char apparence, unsigned short valeurPoints) : Extraterrestre(coord, apparence, valeurPoints), toggle(rand() % 2) {
	this->type = TypeObjetDeJeu::MARTIEN;
}

void Martien::deplacer() {
	this->effacer();
	this->coord.setX(this->coord.getX() + (toggle ? 1 : -1));
	toggle = !toggle;
	this->afficher();
}
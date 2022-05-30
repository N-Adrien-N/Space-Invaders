#include <iostream>
#include "PartiePerdue.h"
#include "TitresDuJeu.h"
#include "UIKit.h"

PartiePerdue::PartiePerdue()
{
	this->score = 0;
}

PartiePerdue::PartiePerdue(unsigned int score)
{
	this->score = score;
}

unsigned int PartiePerdue::getScore()
{
	return this->score;
}

void PartiePerdue::affichagePartiePerdue()
{
	system("cls");
	TitresDuJeu titrePartiePerdue;
	titrePartiePerdue.affichageMessagePartiePerdue();
	std::cout << std::endl << std::endl << std::endl << std::endl;
	std::cout << "\t\t\t" << "  Votre score est de : " << this->getScore() / 2 << std::endl;
	std::cout << std::endl << std::endl << std::endl << std::endl;
}
#include <iostream>
#include "PartieGagnee.h"
#include "TitresDuJeu.h"
#include "UIKit.h"

PartieGagnee::PartieGagnee()
{
	this->score = 0;
}

PartieGagnee::PartieGagnee(unsigned int score)
{
	this->score = score;
}

unsigned int PartieGagnee::getScore()
{
	return this->score;
}

void PartieGagnee::affichagePartieGagnee()
{
	system("cls");
	TitresDuJeu titrePartieGagnee;
	titrePartieGagnee.affichageMessagePartieGagnee();
	std::cout << std::endl << std::endl << std::endl << std::endl;
	std::cout << "\t\t\t" << "  Votre score est de : " << this->getScore() * 2 << std::endl;
	std::cout << std::endl << std::endl << std::endl << std::endl;
}

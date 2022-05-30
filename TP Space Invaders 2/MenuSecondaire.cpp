#include <iostream>
#include "MenuSecondaire.h"
#include "TitresDuJeu.h"
#include "Validations.h"
#include "UIKit.h"
#include "Partie.h"

MenuSecondaire::MenuSecondaire()
{
	this->choixMenuSecondaire = 1;
	this->niveauDeJeu = 100;
}
MenuSecondaire::MenuSecondaire(unsigned short choixMenuSecondaire, unsigned short niveauDeJeu)
{
	this->choixMenuSecondaire = choixMenuSecondaire;
	this->niveauDeJeu = niveauDeJeu;
}

void MenuSecondaire::affichageMenu()
{
	system("cls");
	UIKit::setDimensionFenetre(0, 0, 80, 30);
	UIKit::curseurVisible(true);
	const unsigned short MIN_MENU_SECONDAIRE = 1;
	const unsigned short MAX_MENU_SECONDAIRE = 4;
	Partie partie;
	TitresDuJeu titre;
	titre.affichageTitreDuJeu();
	std::cout << std::endl << std::endl << std::endl << std::endl;
	TitresDuJeu titreMenuSecondaire;
	titreMenuSecondaire.affichageMenuSecondaire();
	std::cout << std::endl << std::endl;
	std::cout << "\t\t\t" << "    ================================ " << std::endl;
	std::cout << "\t\t\t" << "    1 - Facile " << std::endl;
	std::cout << "\t\t\t" << "    2 - Moyen " << std::endl;
	std::cout << "\t\t\t" << "    3 - Difficile " << std::endl;
	std::cout << "\t\t\t" << "    4 - Retourner au menu principal" << std::endl;
	std::cout << "\t\t\t" << "    ================================= " << std::endl;
	std::cout << "\t\t\t" << "    Votre choix : ";
	choixMenuSecondaire = Validations::validerUnsignedShortEntreMinEtMax(MIN_MENU_SECONDAIRE, MAX_MENU_SECONDAIRE);
	SousMenu sousMenu;
	if (choixMenuSecondaire == SousMenu::FACILE)
	{
		setNiveauDeJeu(100);
		partie.debuter();
	}
	else if (choixMenuSecondaire == SousMenu::MOYEN)
	{
		setNiveauDeJeu(50);
		partie.debuter();
	}
	else if (choixMenuSecondaire == SousMenu::DIFFICILE)
	{
		setNiveauDeJeu(35);
		partie.debuter();
	}
	if (choixMenuSecondaire == SousMenu::RETOUR_MENU_PRINCIPAL)
	{
		bool partieTermine = false;
	}
	system("cls");
}
unsigned short MenuSecondaire::getChoixMenuSecondaire()
{
	return this->choixMenuSecondaire;
}

unsigned short MenuSecondaire::getNiveauDeJeu()
{
	return this->niveauDeJeu;
}

void MenuSecondaire::setNiveauDeJeu(unsigned short niveauDeJeu)
{
	this->niveauDeJeu = niveauDeJeu;
}
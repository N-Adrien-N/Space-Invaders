#include <iostream>
#include "MenuPrincipal.h"
#include "MenuSecondaire.h"
#include "TitresDuJeu.h"
#include "Validations.h"
#include "UIKit.h"
#include "Partie.h"
#include "PartieGagnee.h"
#include "PartiePerdue.h"

unsigned short MenuPrincipal::getChoixMenuPrincipal() const
{
	return this->choixMenuPrincipal;
}

void MenuPrincipal::affichageMenu()
{
	const unsigned short MIN_MENU_PRINCIPAL = 1;
	const unsigned short MAX_MENU_PRINCIPAL = 4;
	const unsigned short RETOUR_MENU_PRINCIPAL = 0;
	bool quitter = false;
	do
	{
		PartieGagnee gagner;
		PartiePerdue perdu;
		system("cls");
		UIKit::setDimensionFenetre(0, 0, 80, 30);
		UIKit::curseurVisible(true);
		TitresDuJeu titre;
		titre.affichageTitreDuJeu();
		std::cout << std::endl << std::endl << std::endl << std::endl;
		TitresDuJeu titreMenuPrincipal;
		titreMenuPrincipal.affichageMenuPrincipal();
		std::cout << std::endl << std::endl;
		std::cout << "\t\t\t" << "    =========================  " << std::endl;
		std::cout << "\t\t\t" << "    1 - Debuter une partie " << std::endl;
		std::cout << "\t\t\t" << "    2 - Instructions du jeu " << std::endl;
		std::cout << "\t\t\t" << "    3 - Scores" << std::endl;
		std::cout << "\t\t\t" << "    4 - Quitter " << std::endl;
		std::cout << "\t\t\t" << "    ========================= " << std::endl;
		std::cout << "\t\t\t" << "    Votre choix : ";
		this->choixMenuPrincipal = Validations::validerUnsignedShortEntreMinEtMax(MIN_MENU_PRINCIPAL, MAX_MENU_PRINCIPAL);
		MenuSecondaire choix;
		unsigned short retourMenuPrincipal;
		switch ((Menu)this->choixMenuPrincipal)
		{
		case COMMENCER:
			choix.affichageMenu();
			break;
		case INSTRUCTIONS:
			system("cls");
			std::cout << "  Bienvenue dans la page des instructions" << std::endl << std::endl << std::endl;
			std::cout << "  Le but est de tirer sur tous les extraterrestres existant." << std::endl;
			std::cout << "  - Pour se déplacer, appuyer les touches des fleches :" << std::endl;
			std::cout << "      - Fleche de droite -> pour aller vers la droite," << std::endl;
			std::cout << "      - Fleche de gauche <- pour aller vers la gauche." << std::endl;
			std::cout << "  - Pour tirer des lasers, appuyer sur la touche ESPACE" << std::endl << std::endl;
			std::cout << "  Si la partie est gagnee, le score obtenu est multiplie par 2," << std::endl;
			std::cout << "  si en revanche la partie est perdu, il est alors divise par 2." << std::endl;
			std::cout << std::endl << std::endl << std::endl << std::endl;
			std::cout << "Appuyer sur 0 pour retourner au menu principal : ";
			retourMenuPrincipal = Validations::validerUnsignedShortUnChiffre(RETOUR_MENU_PRINCIPAL);
			break;
		case PAGE_DES_SCORES:
			system("cls");
			std::cout << "Bienvenue dans la page des scores" << std::endl;
			gagner.affichagePartieGagnee();
			perdu.affichagePartiePerdue();
			std::cout << std::endl << std::endl << std::endl << std::endl;
			std::cout << "Appuyer sur 0 pour retourner au menu principal : ";
			retourMenuPrincipal = Validations::validerUnsignedShortUnChiffre(RETOUR_MENU_PRINCIPAL);
			break;
		case QUITTER:
			quitter = true;
			break;

		}
	} while (quitter != true);
	system("cls");
}


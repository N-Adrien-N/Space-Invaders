#include <iostream>
#include <conio.h>
#include "Partie.h"
#include "Vaisseau.h"
#include "UIKit.h"
#include "Martien.h"
#include "Laser.h"
#include "Coord.h"
#include "Extraterrestre.h"
#include "MenuPrincipal.h"
#include "MenuSecondaire.h"
#include "PartieGagnee.h"
#include "PartiePerdue.h"
#include "Validations.h"


void Partie::debuter()
{
	UIKit::setDimensionFenetre(0, 0, 80, 30);
	system("cls");
	MenuSecondaire niveau;
	const unsigned short CADRE_X = 2;
	const unsigned short CADRE_Y = 1;
	const unsigned short CADRE_L = 78;
	const unsigned short CADRE_H = 29;
	bool partieTermine = false;
	const unsigned short MIN_RETOUR_MENU_PRINCIPAL = 0;
	const unsigned short MAX_RETOUR_MENU_PRINCIPAL = 1;
	UIKit::curseurVisible(false);

	//Faire apparaitre le vaisseau
	Coord coordonneesDepartVaisseau(35, 24);
	Coord limiteMouvementGauche(3, 20);
	Coord limiteMouvementDroite(77, 20);
	char apparenceDuVaisseau = 'A';
	Vaisseau vaisseau(apparenceDuVaisseau, coordonneesDepartVaisseau, limiteMouvementGauche, limiteMouvementDroite);

	// Création d'un tableau d'extraterrestres
	const unsigned short NOMBRE_MAX_D_EXTRATERRESTRES = 15;
	Extraterrestre* monTabExtraterrestre[NOMBRE_MAX_D_EXTRATERRESTRES];
	char apparenceExtraterrestre = 'X';
	unsigned short valeurPointsExtraterrestre = 100;
	unsigned short nbExtraterrestre = 8;

	// Création d'un tableau de martien
	const unsigned short NOMBRE_MAX_DE_MARTIENS = 5;
	char apparenceMartien = 'M';
	unsigned short valeurPointsMartien = 200;
	unsigned short nbMartien = 5;
	for (int i = 0; i < (nbExtraterrestre - nbMartien); i++)
	{
		monTabExtraterrestre[i] = new Extraterrestre(Coord((rand() % (55 - 5 + 1) + CADRE_X + 1), (rand() % 15) + CADRE_Y + 1), apparenceExtraterrestre, valeurPointsExtraterrestre);
	}
	for (int i = (nbExtraterrestre - nbMartien); i < nbExtraterrestre; i++)
	{
		monTabExtraterrestre[i] = new Martien(Coord((rand() % (55 - 5 + 1) + CADRE_X + 1), (rand() % 15) + CADRE_Y + 1), apparenceMartien, valeurPointsMartien);
	}

	// Apparitions des lasers
	const unsigned short NOMBRE_MAX_DE_LASERS = 100;
	Laser* lasers[NOMBRE_MAX_DE_LASERS];
	int nombreLasersDepart = 0;
	unsigned int score = 0;
	unsigned int cpt = 0;
	UIKit::gotoXY(31, 1);
	std::cout << "    Score : " << score << "    " << std::endl;
	UIKit::cadre(CADRE_X, CADRE_Y, CADRE_L, CADRE_H, 11);
	do
	{
		//Récupérer la touche appuyée par l'utilisateur
		//Effectuer action en fonction de la touche appuyé par l'utilisateur
		//Ici on peut soit déplacer le vaiseau à gauche ou à droite, soit tirer un laser
		if (GetAsyncKeyState(VK_LEFT))
		{
			vaisseau.deplacer(Direction::GAUCHE);
		}
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			vaisseau.deplacer(Direction::DROITE);
		}

		if (GetAsyncKeyState(VK_SPACE))
		{
			lasers[nombreLasersDepart] = new Laser(vaisseau.getCoord(), TypeLaser::JOUEUR);
			nombreLasersDepart++;
		}

		//Déplacer les lasers du vaisseau et des extraterrestres
		for (int i = 0; i < nombreLasersDepart; i++)
		{
			lasers[i]->deplacer();
		}

		//Retirer les lasers (les effacer)
		for (int i = 0; i < nombreLasersDepart; i++)
		{
			if (lasers[i]->isActif() == false)
			{
				delete lasers[i];
				lasers[i] = lasers[nombreLasersDepart - 1];
				nombreLasersDepart--;
				i--;
			}
		}

		//Déplacer les martiens		
		for (int i = 0; i < nbExtraterrestre; i++)
		{
			UIKit::color(15);
			if ((rand() % 101) >= 95)
			{
				if (monTabExtraterrestre[i]->getType() == TypeObjetDeJeu::MARTIEN) {
					((Martien*)monTabExtraterrestre[i])->deplacer();
				}

			}
		}

		//Faire tirer les extraterrestres
		for (int i = 0; i < nbExtraterrestre; i++)
		{
			if ((rand() % 101) >= 95)
			{
				lasers[nombreLasersDepart] = new Laser(monTabExtraterrestre[i]->getCoord(), TypeLaser::EXTRATERRESTRE);
				nombreLasersDepart++;
			}
		}

		//Vérifier collision entre laser et joueur ou ennemis
		for (int i = 0; i < nombreLasersDepart; i++)
		{
			if (lasers[i]->isActif() == true)
			{
				if (lasers[i]->getTypeLaser() == TypeLaser::EXTRATERRESTRE && vaisseau.detecterCollision(*lasers[i]))
				{
					partieTermine = true;
				}
				else if (lasers[i]->getTypeLaser() == TypeLaser::JOUEUR)
				{
					unsigned int cptExtraterrestre = 0;
					while (cptExtraterrestre < nbExtraterrestre && lasers[i]->isActif() == true)
					{
						if (monTabExtraterrestre[cptExtraterrestre]->detecterCollision(*lasers[i]) == true)
						{
							score += monTabExtraterrestre[cptExtraterrestre]->getValeurPoints();
							UIKit::gotoXY(31, 1);
							std::cout << "    Score : " << score << "    " << std::endl;
							monTabExtraterrestre[cptExtraterrestre]->detruire();
							lasers[i]->detruire();
						}
						cptExtraterrestre++;
					}
				}
			}
		}

		//Retirer les extraterrestres
		for (int i = 0; i < nbExtraterrestre; i++)
		{
			if (monTabExtraterrestre[i]->isActif() == false)
			{
				delete monTabExtraterrestre[i];
				monTabExtraterrestre[i] = monTabExtraterrestre[nbExtraterrestre - 1];
				nbExtraterrestre--;
				i--;
			}
		}

		//Faire apparaitre des nouveaux extraterrestres
		if ((SousMenu)niveau.getChoixMenuSecondaire() == SousMenu::DIFFICILE)
		{
			if ((rand() % 101) >= 20)
			{
				monTabExtraterrestre[nbExtraterrestre] = new Martien(Coord((rand() % (55 - 5 + 1) + CADRE_X + 1), (rand() % 15) + CADRE_Y + 1), apparenceMartien, valeurPointsMartien);
				nbExtraterrestre++;
			}
		}

		//Mettre à jour le score affiché		
		if (cpt % 10 == 0)
		{
			UIKit::gotoXY(31, 1);
			std::cout << "    Score : " << score << "    " << std::endl;
		}

		//Fonction ECHAP pour quitter le jeux et retourner au menu principal
		UIKit::gotoXY(11, 29);
		UIKit::color(3);
		std::cout << "    Appuyer sur ECHAP pour retourner au menu principal    ";
		UIKit::color(15);

		if (GetAsyncKeyState(VK_ESCAPE))
		{
			UIKit::gotoXY(11, 29);
			UIKit::color(3);
			std::cout << "    Quitter la partie en cours ? (0 - Non, 1 - Oui) : ";
			UIKit::curseurVisible(true);
			partieTermine = Validations::validerUnsignedShortEntreMinEtMax(MIN_RETOUR_MENU_PRINCIPAL, MAX_RETOUR_MENU_PRINCIPAL);
			UIKit::color(15);
			if (partieTermine == false)
			{
				UIKit::curseurVisible(false);
			}
		}

		//Vérifier si on gagne (si le nombre d'extraterrestre est rendu à 0)	
		if (nbExtraterrestre == 0)
		{
			PartieGagnee gagner(score);
			gagner.affichagePartieGagnee();
			Sleep(500);
			partieTermine = true;
		}
		//Vérifier si on perd si le nombre d'extra terrestre est à 15+ ou qu'un laser extraterrestre nous a atteint
		else if (nbExtraterrestre >= 15 || partieTermine == true)
		{
			PartiePerdue perdu(score);
			perdu.affichagePartiePerdue();
			Sleep(500);
			partieTermine = true;
		}
		cpt++;
		Sleep(niveau.getNiveauDeJeu());
	} while (partieTermine == false);
	system("pause");
	system("cls");

}
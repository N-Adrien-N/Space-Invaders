#pragma once

enum SousMenu
{
	FACILE = 1,
	MOYEN,
	DIFFICILE,
	RETOUR_MENU_PRINCIPAL
};

class MenuSecondaire
{
	unsigned short choixMenuSecondaire;
	unsigned short niveauDeJeu;

public:
    MenuSecondaire();
	MenuSecondaire(unsigned short choixMenuSecondaire, unsigned short niveauDeJeu);
	unsigned short getNiveauDeJeu();
	unsigned short getChoixMenuSecondaire();
	void setNiveauDeJeu(unsigned short niveauDeJeu);
	virtual void affichageMenu();
};


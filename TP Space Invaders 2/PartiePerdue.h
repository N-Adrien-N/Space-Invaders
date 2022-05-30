#pragma once

#include "Partie.h"

class PartiePerdue : public Partie
{
	unsigned int score;
public:
	PartiePerdue();
	PartiePerdue(unsigned int score);
	unsigned int getScore();
	virtual void affichagePartiePerdue();
};


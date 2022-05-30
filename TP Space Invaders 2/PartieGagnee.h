#pragma once

#include "Partie.h"

class PartieGagnee : public Partie
{
	unsigned int score;
public:
	PartieGagnee();
	PartieGagnee(unsigned int score);
	unsigned int getScore();
	virtual void affichagePartieGagnee();
};
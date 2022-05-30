#include <iostream>
#include "TitresDuJeu.h"
#include "UIKit.h"


void TitresDuJeu::affichageTitreDuJeu()
{ // Police utilisée : Small Slant

    UIKit::color(10);
    std::cout << "                                      _                      __                  " << std::endl;
    std::cout << "       _________  ____ _________     (_)___ _   ______ _____/ /__  __________    " << std::endl;
    std::cout << "      / ___/ __ \\/ __ `/ ___/ _ \\   / / __ \\ | / / __ `/ __  / _ \\/ ___/ ___/" << std::endl;
    std::cout << "     (__  ) /_/ / /_/ / /__/  __/  / / / / / |/ / /_/ / /_/ /  __/ /  (__  )     " << std::endl;
    UIKit::color(3);
    std::cout << "    /____/ .___/\\__,_/\\___/\\___/  /_/_/ /_/|___/\\__,_/\\__,_/\\___/_/  /____/" << std::endl;
    std::cout << "        /_/                                                                      " << std::endl;
    UIKit::color(15);

}


void TitresDuJeu::affichageMenuPrincipal()
{ // Police utilisée : Small Slant

    UIKit::color(3);
    std::cout << "\t" << "     __  ___                         _          _           __   " << std::endl;
    std::cout << "\t" << "    /  |/  /__ ___  __ __  ___  ____(_)__  ____(_)__  ___ _/ /   " << std::endl;
    std::cout << "\t" << "   / /|_/ / -_) _ \\/ // / / _ \\/ __/ / _ \\/ __/ / _ \\/ _ `/ /" << std::endl;
    UIKit::color(10);
    std::cout << "\t" << "  /_/  /_/\\__/_//_/\\_,_/ / .__/_/ /_/_//_/\\__/_/ .__/\\_,_/_/ " << std::endl;
    std::cout << "\t" << "                        /_/                   /_/                " << std::endl;
    UIKit::color(15);

}


void TitresDuJeu::affichageMenuSecondaire()
{ // Police utilisée : Small Slant

    UIKit::color(3);
    std::cout << "\t\t" << "           _  ___                             " << std::endl;
    std::cout << "\t\t" << "          / |/ (_)  _____ ___ ___ ___ __      " << std::endl;
    std::cout << "\t\t" << "         /    / / |/ / -_) _ `/ // | \\ /     " << std::endl;
    UIKit::color(10);
    std::cout << "\t\t" << "        /_/|_/_/|___/\\__/\\_,_/\\_,_/_\\_\\  " << std::endl;
    UIKit::color(15);

}


void TitresDuJeu::affichageMessagePartieGagnee()
{ // Police utilisée : Small Slant

    UIKit::color(3);
    std::cout << "\t\t" << "           _____                __    " << std::endl;
    std::cout << "\t\t" << "          / ___/__ ____ ____  _/_/    " << std::endl;
    std::cout << "\t\t" << "         / (_ / _ `/ _ `/ _ \\/ -_)   " << std::endl;
    UIKit::color(10);
    std::cout << "\t\t" << "         \\___/\\_,_/\\_, /_//_/\\__/ " << std::endl;
    std::cout << "\t\t" << "                  /___/               " << std::endl;
    UIKit::color(15);

}


void TitresDuJeu::affichageMessagePartiePerdue()
{ // Police utilisée : Small Slant

    UIKit::color(3);
    std::cout << "\t\t" << "             ___             __       " << std::endl;
    std::cout << "\t\t" << "            / _ \\___ _______/ /_ __  " << std::endl;
    std::cout << "\t\t" << "           / ___/ -_) __/ _  / // /   " << std::endl;
    UIKit::color(10);
    std::cout << "\t\t" << "          /_/   \\__/_/  \\_,_/\\_,_/ " << std::endl;
    UIKit::color(15);

}

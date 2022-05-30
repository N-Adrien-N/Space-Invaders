#include <iostream>
#include "UIKit.h"
#include "MenuPrincipal.h"

using namespace std;

int main()
{
    UIKit::setDimensionFenetre(0, 0, 80, 30);
    MenuPrincipal menu;
    menu.affichageMenu();
    return 0;
}
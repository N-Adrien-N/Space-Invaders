#pragma once

enum Menu
{
    COMMENCER = 1,
    INSTRUCTIONS,
    PAGE_DES_SCORES,
    QUITTER
};



class MenuPrincipal
{
    unsigned short choixMenuPrincipal;
public:
    unsigned short getChoixMenuPrincipal() const;
    virtual void affichageMenu();
};
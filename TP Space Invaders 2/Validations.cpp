#include "Validations.h"
#include <iostream>




/* -------------------- ~ INT (4 octets) ~ -------------------- */

// - INT  ->  Validation numérique
int Validations::validerInt()
{
    int valeur;
    std::cin >> valeur;
    while (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cin.clear();
        std::cin.ignore(512, '\n');
        std::cout << "Valeur numérique seulement : ";
        std::cin >> valeur;
    }
    std::cin.ignore(512, '\n');
    return valeur;
}

// - INT  ->  Validation entre MIN et MAX
int Validations::validerIntEntreMinEtMax(const int MIN, const int MAX)
{
    int valeur = Validations::validerInt();
    while (valeur < MIN || valeur > MAX)
    {
        std::cout << "Valeur entre " << MIN << " et " << MAX << " seulement : ";
        valeur = Validations::validerInt();
    }
    return valeur;
}




/* -------------------- ~ UNSIGNED INT (4 octets) ~ -------------------- */

// - UNSIGNED INT  ->  Validation numérique
unsigned int Validations::validerUnsignedInt()
{
	unsigned int valeur;
    std::cin >> valeur;
    while (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cin.clear();
        std::cin.ignore(512, '\n');
        std::cout << "Valeur numérique seulement : ";
        std::cin >> valeur;
    }
    std::cin.ignore(512, '\n');
    return valeur;
}

// - UNSIGNED INT  ->  Validation entre MIN et MAX
unsigned int Validations::validerUnsignedIntEntreMinEtMax(const unsigned int MIN, const unsigned int MAX)
{
    unsigned int valeur = Validations::validerUnsignedInt();
    while (valeur < MIN || valeur > MAX)
    {
        std::cout << "Valeur entre " << MIN << " et " << MAX << " seulement : ";
        valeur = Validations::validerUnsignedInt();
    }
    return valeur;
}




/* -------------------- ~ FLOAT (4 octets) ~ -------------------- */

// - FLOAT  ->  Validation numérique
float Validations::validerFloat()
{
    float valeur;
    std::cin >> valeur;
    while (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cin.clear();
        std::cin.ignore(512, '\n');
        std::cout << "Valeur numérique seulement : ";
        std::cin >> valeur;
    }
    std::cin.ignore(512, '\n');
    return valeur;
}

// - FLOAT  ->  Validation entre MIN et MAX
float Validations::validerFloatEntreMinEtMax(const float MIN, const float MAX)
{
    float valeur = Validations::validerFloat();
    while (valeur < MIN || valeur > MAX)
    {
        std::cout << "Valeur entre " << MIN << " et " << MAX << " seulement : ";
        valeur = Validations::validerFloat();
    }
    return valeur;
}




/* -------------------- ~ SHORT (2 octets) ~ -------------------- */

// - SHORT  ->  Validation numérique
short Validations::validerShort()
{
    short valeur;
    std::cin >> valeur;
    while (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cin.clear();
        std::cin.ignore(512, '\n');
        std::cout << "Valeur numérique seulement : ";
        std::cin >> valeur;
    }
    std::cin.ignore(512, '\n');
    return valeur;
}

// - SHORT  ->  Validation entre MIN et MAX
short Validations::validerShortEntreMinEtMax(const short MIN, const short MAX)
{
    short valeur = Validations::validerShort();
    while (valeur < MIN || valeur > MAX)
    {
        std::cout << "Valeur entre " << MIN << " et " << MAX << " seulement : ";
        valeur = Validations::validerShort();
    }
    return valeur;
}




/* -------------------- ~ UNSIGNED SHORT (2 octets) ~ -------------------- */

// - UNSIGNED SHORT  ->  Validation numérique
unsigned short Validations::validerUnsignedShort()
{
    unsigned short valeur;
    std::cin >> valeur;
    while (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cin.clear();
        std::cin.ignore(512, '\n');
        std::cout << "Valeur numérique seulement : ";
        std::cin >> valeur;
    }
    std::cin.ignore(512, '\n');
    return valeur;
}

// - UNSIGNED SHORT  ->  Validation entre MIN et MAX
unsigned short Validations::validerUnsignedShortUnChiffre(const unsigned short CHIFFRE)
{
    unsigned short valeur = Validations::validerUnsignedShort();
    while (valeur != CHIFFRE)
    {
        std::cout << "Valeur " << CHIFFRE << " seulement : ";
        valeur = Validations::validerUnsignedShort();
    }
    return valeur;
}

// - UNSIGNED SHORT  ->  Validation entre MIN et MAX
unsigned short Validations::validerUnsignedShortEntreMinEtMax(const unsigned short MIN, const unsigned short MAX)
{
    unsigned short valeur = Validations::validerUnsignedShort();
    while (valeur < MIN || valeur > MAX)
    {
        std::cout << "Valeur entre " << MIN << " et " << MAX << " seulement : ";
        valeur = Validations::validerUnsignedShort();
    }
    return valeur;
}



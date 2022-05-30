#pragma once


class Validations
{
public:




    /* -------------------- ~ INT (4 octets) ~ -------------------- */

    // - INT  ->  Validation num�rique
    static int validerInt();

    // - INT  ->  Validation entre MIN et MAX
    static int validerIntEntreMinEtMax(const int MIN, const int MAX);




    /* -------------------- ~ UNSIGNED INT (4 octets) ~ -------------------- */

    // - UNSIGNED INT  ->  Validation num�rique
    static unsigned int validerUnsignedInt();

    // - UNSIGNED INT  ->  Validation entre MIN et MAX
    static unsigned int validerUnsignedIntEntreMinEtMax(const unsigned int MIN, const unsigned int MAX);




    /* -------------------- ~ FLOAT (4 octets) ~ -------------------- */

    // - FLOAT  ->  Validation num�rique
    static float validerFloat();

    // - FLOAT  ->  Validation entre MIN et MAX
    static float validerFloatEntreMinEtMax(const float MIN, const float MAX);




    /* -------------------- ~ SHORT (2 octets) ~ -------------------- */

    // - SHORT  ->  Validation num�rique
    static short validerShort();

    // - SHORT  ->  Validation entre MIN et MAX
    static short validerShortEntreMinEtMax(const short MIN, const short MAX);




    /* -------------------- ~ UNSIGNED SHORT (2 octets) ~ -------------------- */

    // - UNSIGNED SHORT  ->  Validation num�rique
    static unsigned short validerUnsignedShort();

    // - UNSIGNED SHORT  ->  Validation un chiffre
    static unsigned short validerUnsignedShortUnChiffre(const unsigned short CHIFFRE);

    // - UNSIGNED SHORT  ->  Validation entre MIN et MAX
    static unsigned short validerUnsignedShortEntreMinEtMax(const unsigned short MIN, const unsigned short MAX);

};


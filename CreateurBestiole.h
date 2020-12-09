#ifndef CREATEURBESTIOLE_H
#define CREATEURBESTIOLE_H

#include "Configuration.h"
#include "CreateurBestiole.h"
#include "Createur.h"
#include "Comportement.h"
#include "Multiple.h"
#include "Gregaire.h"
#include "Peureuse.h"
#include "Kamikaze.h"
#include "Prevoyante.h"
#include "Bestiole.h"
#include "BestioleSimple.h"
#include "Oreille.h"
#include "Yeux.h" 
#include "Nageoire.h"
#include "Carapace.h"
#include "Camouflage.h"
#include "Createur.h"

#include "RandomUtils.h"

class CreateurBestiole : public Createur
{   private:
         //random generators
        Rand_double vitesse;
        Rand_int    age;
        Rand_double alpha;
        Rand_double deltaY;
        Rand_double gammaY;
        Rand_double deltaO;
        Rand_double gammaO;
        Rand_double nu;
        Rand_double omega;
        Rand_double eta;
        Rand_double psi;
        Rand_int x;
        Rand_int y;
        Rand_double orientation;
    public:
        CreateurBestiole();
        ~CreateurBestiole();
        Bestiole * createBestiole(Comportement* c)//,unsigned char _color[3]);
}

#endif
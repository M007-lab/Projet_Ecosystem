#ifndef BESTIOLES_GR3_FABRIQUEESPECEA_H
#define BESTIOLES_GR3_FABRIQUEESPECEA_H

#include "Configuration.h"
#include "CreateurBestiole.h"
#include "Comportement.h"
#include "Multiple.h"
#include "Gregaire.h"
#include "Peureuse.h"
#include "Kamikaze.h"
#include "Prevoyante.h"
#include "Bestiole.h"
#include "BestioleSimple.h"
#include "Oreille.h"
#include "Yeux.h" //Oeil
#include "Nageoire.h"
#include "Carapace.h"
#include "Camouflage.h"

class CreateurBestiole : public Createur
{
    public:
        CreateurBestiole();
}
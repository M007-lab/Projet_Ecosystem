#ifndef CAMOUFLAGE_H
#define CAMOUFLAGE_H

#include "Accesoire.h"
class Camouflage:public Accesoire
{
private:
    double capaciteCamouflage;
public:
    Camouflage(BestioleSimple* base,double capacite);
    double getCamouflage() override;


}
#endif
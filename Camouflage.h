#ifndef CAMOUFLAGE_H
#define CAMOUFLAGE_H

#include "AccesoireDecorateur.h"
class Camouflage:public AccesoireDecorateur
{
private:
    double capaciteCamouflage;
public:
    Camouflage(Bestiole* base,double capacite);
    double getCamouflage() override;
    virtual Bestiole* cloner();
    virtual void draw(UImg& support);


};
#endif
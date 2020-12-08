#ifndef CAMOUFLAGE_H
#define CAMOUFLAGE_H

#include "AccesoireDecorateur.h"
class Camouflage:public AccesoireDecorateur
{
private:
    double capaciteCamouflage;
public:
    Camouflage(Bestiole* base,double capacite);

    double getCamouflage() const override;
    virtual Bestiole* cloner();
    virtual void draw(UImg& support);


    double getCamouflage() ;
    void draw(UImg& support);


};
#endif
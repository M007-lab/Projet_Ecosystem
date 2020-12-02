#ifndef CARAPACE_H
#define CARAPACE_H

#include "AccesoireDecorateur.h"

class Carapace:public AccesoireDecorateur
{
private:
    double coefReducMort;
    double coefVitesse;
public:
    Carapace(Bestiole* base,double coefMort, double coefVitesse);
    double getCamouflage() override;
    double getProbaMort() override;
    double getVitesse() override;
    virtual Bestiole* cloner();
    virtual void draw(UImg& support);


};
#ifndef CARAPACE_H
#define CARAPACE_H

#include "AccesoireDecorateur.h"

class Carapace:public AccesoireDecorateur
{
private:
    double coefCarapaceMort;
    double coefCarapaceVitesse;
public:
    Carapace(Bestiole* base, double coefMort, double coefVitesse);
    double getProbaMort() override;
    double getVitesse() override;
    void draw(UImg& support);


};
#endif
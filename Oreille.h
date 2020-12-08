#ifndef OREILLE_H
#define OREILLE_H

#include "CapteurDecorateur.h"

class Oreille : public Capteur {
    double distance;
    double angle = 360 const;
    double capaciteDetection;

public :
    Oreille(BestioleSimple* base, double detec, double dist);
    bool jeTeVois(const Bestiole & autre) const override;
    void draw(UImg& support);
    bool isOreille(CapteurDecorateur *capDec);// Verify if an element of the list capteurDecorateurs is an instance of the Oreille
    Oreille* castOreille(CapteurDecorateur *capDec); // DownCast a CapteurDecorateur to Oreille

};

#endif
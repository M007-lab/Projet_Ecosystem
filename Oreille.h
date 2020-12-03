#ifndef OREILLE_H
#define OREILLE_H

#include "CapteurDecorateur.h"

class Oreille : public CapteurDecorateur {
    Oreille(){};
public :
    Oreille(BestioleSimple* base, double detec, double dist);
    bool jeTeVois(const Bestiole & autre) const override;
    virtual BestioleSimple* cloner();
    virtual void draw(UImg& support);

};

#endif
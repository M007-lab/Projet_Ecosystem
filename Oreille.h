#ifndef OREILLE_H
#define OREILLE_H

#include "CapteurDecorateur.h"

class Oreille : public CapteurDecorateur {
    double distance;
    const double angle;
    double capaciteDetection;

public :
    Oreille(Bestiole* base, double detec, double dist);
    bool jeTeVois(const Bestiole & b) const override;
    void toString(std::ostringstream stream) override;
    void draw(UImg& support) override;

    friend std::ostream& operator<<(std::ostream& flot , const Oreille& oreille) ;
};

#endif
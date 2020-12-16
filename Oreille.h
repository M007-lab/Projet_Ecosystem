#ifndef OREILLE_H
#define OREILLE_H

#include "CapteurDecorateur.h"

class Oreille : public CapteurDecorateur {

    static constexpr double      ANGLE = 360;

    double distance;
    // const double angle;
    double capaciteDetection;

public :
    Oreille(ConcreteBestiole* base, double detec, double dist);
    ConcreteBestiole* getBase() const override;
    std::string getName() const override;
    ConcreteBestiole* clone();
    bool jeTeVois(const Bestiole & b) const override;
    void toString(std::ofstream& stream) override;
    void draw(UImg& support) override;

    friend std::ostream& operator<<(std::ostream& flot , const Oreille& oreille) ;
};

#endif
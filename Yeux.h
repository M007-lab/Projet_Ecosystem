#ifndef YEUX_H
#define YEUX_H

#include "CapteurDecorateur.h"

class Yeux : public CapteurDecorateur {
    double distance;
    double angle ;
    double capaciteDetection;

public :
    Yeux(ConcreteBestiole* base, double detec, double dist, double angle);
    ConcreteBestiole* getBase() const;
    std::string getName() const;
    ConcreteBestiole* clone();
    bool jeTeVois(const Bestiole & b) const override;
    // bool dansDistanceDetection(const Bestiole & b) const;
    // bool dansChampAngulaire(const Bestiole & b) const;
    void toString(std::ostringstream stream) override;
    void draw(UImg& support) override;


    friend std::ostream& operator<<(std::ostream& flot , const Yeux& yeux) ;

};

#endif
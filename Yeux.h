#ifndef YEUX_H
#define YEUX_H

#include "Capteur.h"

class Yeux : public Capteur {
    double distance;
    double angle ;
    double capaciteDetection;

public :
    Yeux(BestioleSimple* base, double detec, double dist, double angle);
    bool jeTeVois(const Bestiole & autre) const override;
    void draw(UImg& support);
    bool isYeux(CapteurDecorateur *capDec);// Verify if an element of the list capteurDecorateurs is an instance of the Yeux
    Yeux* castYeux(CapteurDecorateur *capDec); // DownCast a CapteurDecorateur to Oreille

};

#endif
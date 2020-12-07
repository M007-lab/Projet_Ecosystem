#ifndef _BESTIOLESIMPLE_H
#define _BESTIOLESIMPLE_H

#include "Bestiole.h"
#include "Comportement.h"
#include "RandomUtils.h"

class BestioleSimple: public Bestiole {
    Comportement *comportement;
public:
    BestioleSimple(){};
    BestioleSimple(int _x,int _y, int _ageMax, double _vitesse, double _orientation,Comportement* c, unsigned char* _color);
    virtual ~BestioleSimple();
    // BestioleSimple(const BestioleSimple& b);
    // bool jeTeVois(const Bestiole&) const override;
    Bestiole* clone() override;

    Comportement* getComportement() const override;
    double getCamouflage() const override;
    // void draw(UImg& support) override;
    virtual void getDecorateurs(std::list<std::string> &decorateurs) override;


};
#endif
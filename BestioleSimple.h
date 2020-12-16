
#ifndef _CONCRETEBESTIOLE_H
#define _CONCRETEBESTIOLE_H

#include "ConcreteBestiole.h"
#include "Comportement.h"
class BestioleSimple: public ConcreteBestiole {
    Comportement * comportement;
public:
    BestioleSimple(){};
    BestioleSimple(int _x,int _y, int _ageMax, double _vitesse, double _orientation,Comportement* c, unsigned char* _color);
    virtual ~BestioleSimple();
    BestioleSimple(const BestioleSimple& b);
    ConcreteBestiole* clone() override;
    Comportement* getComportement() const override;
    double getCamouflage() const override;
    // void draw(UImg& support) override;
    //virtual void getDecorateurs(std::list<std::string> &decorateurs) override;


};


#endif 
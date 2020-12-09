#ifndef _BESTIOLESIMPLE_H
#define _BESTIOLESIMPLE_H

#include "Bestiole.h"
#include "Comportement.h"



class BestioleSimple: public Bestiole {
    Comportement *comportement;
public:
    BestioleSimple(){};
    BestioleSimple(int _x,int _y, int _ageMax, double _vitesse, double _orientation,Comportement* c, unsigned char* _color);
    virtual ~BestioleSimple();
    BestioleSimple(const BestioleSimple& b);
    bool jeTeVois(const Bestiole&) const override;
    Bestiole* clone() override;
    void action( Milieu & monMilieu ) override;
    void toString(iostream & out) override;
    Comportement* getComportement() const;
    double getCamouflage() const override;
    void draw(UImg& support) override;
    // virtual void getDecorateurs(std::list<std::string> &decorateurs) override;


};
#endif
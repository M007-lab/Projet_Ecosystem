#ifndef _ACCESSOIREDECORATEUR_H
#define _ACCESSOIREDECORATEUR_H

#include "ConcreteBestiole.h"

class AccessoireDecorateur : public ConcreteBestiole {
protected :
    std::string name;
    ConcreteBestiole* base;

public :
    virtual ~AccessoireDecorateur(){};

    virtual ConcreteBestiole* getBase() const = 0;
    virtual std::string getName() const = 0;
    
    virtual ConcreteBestiole* clone() = 0;
    Comportement* getComportement() const ;

    virtual double getVitesse() const override = 0 ;
    virtual double getCamouflage() const override = 0 ;
    virtual double getProbaMort() const override  = 0;

    virtual void toString(ofstream& stream) = 0;
    virtual void draw(UImg& support) = 0;

};
#endif
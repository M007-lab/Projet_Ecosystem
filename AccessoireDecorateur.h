#ifndef _ACCESSOIREDECORATEUR_H
#define _ACCESSOIREDECORATEUR_H

#include "ConcreteBestiole.h"

class AccessoireDecorateur : public ConcreteBestiole {
protected :
    std::string name;
    ConcreteBestiole* base;

public :
    virtual ~AccessoireDecorateur();

    ConcreteBestiole* getBase() const;
    std::string getName() const;

    virtual double getVitesse() const override ;
    virtual double getCamouflage() const override;
    virtual double getProbaMort() const override;

    virtual void toString(std::ostringstream stream) = 0;
    virtual void draw(UImg& support) = 0;

};
#endif
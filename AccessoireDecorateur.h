#ifndef _ACCESSOIREDECORATEUR_H
#define _ACCESSOIREDECORATEUR_H

#include "BestioleSimple.h"

class AccessoireDecorateur : public BestioleSimple {
protected :
    std::string name;
    BestioleSimple* base;

public :
    virtual ~AccessoireDecorateur();

    BestioleSimple* getBase() const;
    std::string getName() const;

    virtual double getVitesse() const override ;
    virtual double getCamouflage() const override;
    virtual double getProbaMort() const override;

    virtual void toString(std::ostringstream stream) = 0;
    virtual void draw(UImg& support) = 0;

};
#endif
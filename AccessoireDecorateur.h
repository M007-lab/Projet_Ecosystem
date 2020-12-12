#ifndef _ACCESSOIREDECORATEUR_H
#define _ACCESSOIREDECORATEUR_H

#include "Bestiole.h"

class AccessoireDecorateur : public Bestiole {
protected :
    std::string name;
    Bestiole* base;

public :
    virtual ~AccessoireDecorateur();

    Bestiole* getBase() const;
    std::string getName() const;

    virtual double getVitesse() const override ;
    virtual double getCamouflage() const override;
    virtual double getProbaMort() const override;

    virtual void toString() = 0;
    virtual void draw(UImg& support) = 0;

};
#endif
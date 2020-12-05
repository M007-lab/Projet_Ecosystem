#ifndef GREGAIRE_H
#define GREGAIRE_H

#include "Comportement.h"
class Gregaire:public Comportement{
public:
    virtual void executeBehavior(Bestiole* bestiole) override;
    virtual Gregaire* dupliquer() const override;
     ~Gregaire(){};
    virtual std::string getName() override;
};

#endif
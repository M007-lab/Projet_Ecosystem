#ifndef GREGAIRE_H
#define GREGAIRE_H

#include "Comportement.h"
class Gregaire:public Comportement{
public: 
    void executeBehavior(Bestiole* bestiole,Milieu& milieu) override;
    virtual Gregaire* dupliquer() const override;
     ~Gregaire(){};
    virtual std::string getName() override;
};

#endif
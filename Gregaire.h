#ifndef GREGAIRE_H
#define GREGAIRE_H

#include "Comportement.h"
class Gregaire:public Comportement{
public:
    void executeBehavior(Bestiole* bestiole) override;
    Comportement* dupliquer() const override;
     ~Gregaire(){};
    std::string getName() override;
};

#endif
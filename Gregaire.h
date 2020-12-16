#ifndef GREGAIRE_H
#define GREGAIRE_H

#include "Comportement.h"

class Gregaire:public Comportement{
public: 
    void executeBehavior(Bestiole* bestiole,std::list<Bestiole*> voisins) override;
    virtual Gregaire* dupliquer() const override;
     ~Gregaire();
    virtual std::string getName() override;
};

#endif
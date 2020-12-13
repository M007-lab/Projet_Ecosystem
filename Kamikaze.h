#ifndef KAMIKAZE_H
#define KAMIKAZE_H

#include "Comportement.h"

class Kamikaze:public Comportement{
public:
    void executeBehavior(Bestiole* bestiole, std::list<Bestiole*> voisins) override;
    virtual Kamikaze* dupliquer() const override;
     ~Kamikaze();
    virtual std::string getName() override;
};

#endif
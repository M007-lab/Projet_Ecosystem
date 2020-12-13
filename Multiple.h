#ifndef MULTIPLE_H
#define MULTIPLE_H

#include "Comportement.h"


class Multiple: public Comportement {
    Comportement* comportement;
public:
    ~Multiple();
    void executeBehavior(Bestiole* bestiole,std::list<Bestiole*> voisins) override;
    virtual Multiple* dupliquer() const override;
    virtual std::string getName() override;
};


#endif 
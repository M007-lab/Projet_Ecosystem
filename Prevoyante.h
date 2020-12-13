#ifndef PREVOYANTE_H
#define PREVOYANTE_H

#include "Comportement.h"


class Prevoyante: public Comportement {
public:
    void executeBehavior(Bestiole* bestiole, std::list<Bestiole*> voisins) override;
    virtual Prevoyante* dupliquer() const override;
    double getMesurePrincipale(double direction);
    ~Prevoyante();
    virtual std::string getName() override;
};


#endif 
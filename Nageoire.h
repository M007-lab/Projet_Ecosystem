#ifndef NAGEOIRE_H
#define NAGEOIRE_H

#include "AccessoireDecorateur.h"
#include "Bestiole.h"
class Nageoire : public AccessoireDecorateur {
private:
    double coefNageoire;

public:
    Nageoire(ConcreteBestiole* base, double coefVitesse);
    double getCamouflage() const override;
    double getVitesse() const override ;
    double getProbaMort() const override ;
    
    ConcreteBestiole* clone();
    void toString(std::ostringstream stream) override;
    ConcreteBestiole* getBase() const;
    std::string getName() const;
    void draw(UImg& support);

    friend std::ostream& operator<<(std::ostream& flot , const Nageoire& ngeoire) ;
};
#endif
#ifndef _CAMOUFLAGE_H
#define _CAMOUFLAGE_H

#include "AccessoireDecorateur.h"

class Camouflage : public AccessoireDecorateur {
private:
    double capaciteCamouflage;

public:
    Camouflage(ConcreteBestiole* base, double capacite);
    double getCamouflage() const override;
    double getVitesse() const override ;
    double getProbaMort() const override ;
    
    ConcreteBestiole* clone();
    ConcreteBestiole* getBase() const;
    std::string getName() const;
    void toString(std::ostringstream stream) override;
    void draw(UImg& support) override;

    friend std::ostream& operator<<(std::ostream& flot , const Camouflage& camouflage) ;

};
#endif
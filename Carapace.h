#ifndef CARAPACE_H
#define CARAPACE_H

#include "AccessoireDecorateur.h"
#include "Bestiole.h" 
class Carapace : public AccessoireDecorateur{
private:
    double coefCarapaceMort;
    double coefCarapaceVitesse;

public:
    Carapace(ConcreteBestiole* base, double coefMort, double coefVitesse);
    double getCamouflage() const override;
    double getVitesse() const override ;
    double getProbaMort() const override ;

    ConcreteBestiole* clone();
    ConcreteBestiole* getBase() const;
    std::string getName() const;
    void toString(std::ofstream& stream) override;
    void draw(UImg& support) override;

    friend std::ostream& operator<<(std::ostream& flot , const Carapace& carapace) ;
};
#endif
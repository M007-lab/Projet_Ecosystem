#ifndef CARAPACE_H
#define CARAPACE_H

#include "AccessoireDecorateur.h"

class Carapace : public AccessoireDecorateur{
private:
    double coefCarapaceMort;
    double coefCarapaceVitesse;

public:
    Carapace(Bestiole* base, double coefMort, double coefVitesse);
    double getProbaMort() override;
    double getVitesse() override;
    void toString() override;
    void draw(UImg& support) override;

    friend std::ostream& operator<<(std::ostream& flot , const Nageoire& nageoire) ;
};
#endif
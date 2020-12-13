#ifndef CARAPACE_H
#define CARAPACE_H

#include "AccessoireDecorateur.h"
#include "Bestiole.h" 
class Carapace : public AccessoireDecorateur{
private:
    double coefCarapaceMort;
    double coefCarapaceVitesse;

public:
    Carapace(Bestiole* base, double coefMort, double coefVitesse);
    double getProbaMort() const override;
    double getVitesse() const override;
    void toString(std::ostringstream stream) override;
    void draw(UImg& support) override;

    friend std::ostream& operator<<(std::ostream& flot , const Carapace& carapace) ;
};
#endif
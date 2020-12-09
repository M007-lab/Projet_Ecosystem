#ifndef NAGEOIRE_H
#define NAGEOIRE_H

#include "AccessoireDecorateur.h"

class Nageoire : public AccessoireDecorateur {
private:
    double coefNageoire;

public:
    Nageoire(Bestiole* base, double coefVitesse);
    double getVitesse() override;
    void toString(std::ostringstream stream) override;
    void draw(UImg& support);

    friend std::ostream& operator<<(std::ostream& flot , const Carapace& carapace) ;
};
#endif
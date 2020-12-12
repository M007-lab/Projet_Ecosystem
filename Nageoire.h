#ifndef NAGEOIRE_H
#define NAGEOIRE_H

#include "AccesoireDecorateur.h"

class Nageoire : public AccesoireDecorateur {
private:
    double coefNageoire;

public:
    Nageoire(Bestiole* base, double coefVitesse);
    double getVitesse() override;
    void toString() override;
    void draw(UImg& support);

    friend std::ostream& operator<<(std::ostream& flot , const Carapace& carapace) ;
};
#endif
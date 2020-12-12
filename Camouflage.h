#ifndef CAMOUFLAGE_H
#define CAMOUFLAGE_H

#include "AccesoireDecorateur.h"

class Camouflage : public AccesoireDecorateur {
private:
    double capaciteCamouflage;

public:
    Camouflage(Bestiole* base, double capacite);
    double getCamouflage() override;
    void toString() override;
    void draw(UImg& support) override;

    friend std::ostream& operator<<(std::ostream& flot , const Camouflage& camouflage) ;

};
#endif
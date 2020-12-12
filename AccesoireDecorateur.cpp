#include "AccessoireDecorateur.h"

Bestiole* AccessoireDecorateur::getBase() const{
    return this->base;
}

std::string AccessoireDecorateur::getName() const{
    return this->name;
}

double AccessoireDecorateur::getVitesse() const {
    return this->getBase()->getVitesse();
}

double AccessoireDecorateur::getCamouflage() const {
    return this->getBase()->getCamouflage();
}

double AccessoireDecorateur::getProbaMort() const {
    return this->getBase()->getProbaMort();
}

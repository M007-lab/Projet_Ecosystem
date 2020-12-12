#include "AccessoireDetecteur.h"

Bestiole* AccessoireDecorateur::getBase() const{
    return this->base;
}

std::string AccessoireDecorateur::getName() const{
    return this->name;
}


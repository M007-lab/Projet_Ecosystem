#include "CapteurDecorateur.h"

Bestiole* CapteurDecorateur::getBase() const{
    return this->base;
}

std::string CapteurDecorateur::getName() const{
    return this->name;
}

std::list<CapteurDecorateur> CapteurDecorateur::getCapteurDecorateurs() override {
    return this->capteurDecorateurs;
}
#include "AccessoireDecorateur.h"

Bestiole* AccessoireDecorateur::getBase() const{
    return this->base;
}

std::string AccessoireDecorateur::getName() const{
    return this->name;
}

std::list<AccessoireDecorateur> AccessoireDecorateur::getAccessoireDecorateurs() override {
    return this->accessoiresDecorateurs;
}
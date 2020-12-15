#include "AccessoireDecorateur.h"

// ConcreteBestiole* AccessoireDecorateur::getBase() const{
//     return this->base;
// }

// std::string AccessoireDecorateur::getName() const{
//     return this->name;
// }
Comportement* AccessoireDecorateur::getComportement() const
{
    return this->getBase()->getComportement();
}

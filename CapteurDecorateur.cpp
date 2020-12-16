#include "CapteurDecorateur.h"

// ConcreteBestiole* CapteurDecorateur::getBase() const{
//     return this->base;
// }

// std::string CapteurDecorateur::getName() const{
//     return this->name;
// }
Comportement* CapteurDecorateur::getComportement() const
{
    return this->getBase()->getComportement();
}
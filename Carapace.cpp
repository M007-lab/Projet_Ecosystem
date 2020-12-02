#include "Carapace.h"

double Carapace::getVitesse() const {
  return 1/coefVitesse * this->getBase()->getVitesse(); // this->getVitesse() won't work cause call in loop
}

double Carapace::getProbaMort() const {
   return this->getBase()->getProbaMort() / coefReducMort ;
}

#include "Camouflage.h"

Camouflage::Camouflage(Bestiole* base, double capacite) {
  this->name = "Camouflage";
  this->base = base;
  this->capaciteCamouflage = capacite;
}

double Camouflage::getCamouflage() const {
  return this->capaciteCamouflage + this->getBase()->getCamouflage();
}

void Camouflage::toString(std::ostringstream stream) {
    std::ostringstream stream;
    stream << this ;
    // std::string str =  stream.str();
}

void Camouflage::draw(UImg& support) {
    this->getBase()->draw(support);
    support.draw_circle(this->getX(),this->getY(), Config::getInstance()->rayon - 3, this->getLightColor()); // Dessine un cerle gris au sein de la besitole
}

std::ostream& operator<<(std::ostream& flot , const Camouflage& camouflage) {
    flot << camouflage.getBase() << "," << camouflage.getName() << "," << camouflage.capaciteCamouflage << "\n";
    return flot ;
}
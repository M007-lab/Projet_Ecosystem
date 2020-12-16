#include "Camouflage.h"

Camouflage::Camouflage(ConcreteBestiole* base, double capacite) {
  this->name = "Camouflage";
  this->base = base;
  this->capaciteCamouflage = capacite;
}

double Camouflage::getCamouflage() const {
  return this->capaciteCamouflage + this->getBase()->getCamouflage();
}
double Camouflage::getVitesse() const {
    return this->getBase()->getVitesse();
}
double Camouflage::getProbaMort() const {
    return this->getBase()->getProbaMort();
}

ConcreteBestiole* Camouflage::getBase() const{return base;}
std::string Camouflage::getName() const{return name;}

ConcreteBestiole* Camouflage::clone() {
  return new Camouflage(this->getBase()->clone(), this->capaciteCamouflage);
}

void Camouflage::toString(std::ofstream& stream) {
    // std::ofstream& stream;
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
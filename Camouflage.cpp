#include "Camouflage.h"
#include <iostream>

Camouflage::Camouflage(Bestiole* base, double val) {
  this->name = "Camouflage";
  this->base = base;
  this->capaciteCamouflage = val;
    this->accessoiresDecorateurs.push_back(this);

}

double Camouflage::getCamouflage() const {
  return this->capaciteCamouflage + this->getBase()->getCamouflage();
}

void Camouflage::draw(UImg& support) {
  this->getBase()->draw(support);
  support.draw_circle(this->getPosition(),Config::getInstance()->rayon - 3,getLightColor()); // Dessine un cerle gris au sein de la besitole
}
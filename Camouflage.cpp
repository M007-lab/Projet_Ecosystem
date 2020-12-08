#include "Camouflage.h"
#include <iostream>

Camouflage::Camouflage(Bestiole* base, double val) {
  this->name = "Camouflage";
  this->base = base;
  this->capaciteCamouflage = val;
}

double Camouflage::getCamouflage() const {
  return this->capaciteCamouflage + this->getBase()->getCamouflage();
}

// Bestiole* Camouflage::clone() {
//   return new Camouflage(this->getBase()->clone(), this->capaciteCamouflage);
// }

// void Camouflage::draw(UImg& support) {
//   this->getBase()->draw(support);
//   support.draw_circle(this->getPosition(),Config::getInstance()->rayon - 3,getLightColor()); // Dessine un cerle gris au sein de la besitole
// }
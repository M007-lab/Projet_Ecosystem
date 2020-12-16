#include "CapteurDecorateur.h"

// ConcreteBestiole* CapteurDecorateur::getBase() const{
//     return this->base;
// }

// std::string CapteurDecorateur::getName() const{
//     return this->name;
// }
#include "AccessoireDecorateur.h"

// ConcreteBestiole* AccessoireCapteurDecorateur::getBase() const{
//     return this->base;
// }

// std::string AccessoireCapteurDecorateur::getName() const{
//     return this->name;
// }
Comportement* CapteurDecorateur::getComportement() const
{
    return this->getBase()->getComportement();
}
bool CapteurDecorateur::jeTeVois(const Bestiole & autre) const {
  return this->getBase()->jeTeVois(autre);
}

void CapteurDecorateur::collide(Bestiole& bestiole)
{
    this->getBase()->collide(bestiole);
}


void CapteurDecorateur::setX(int newX) {
  this->getBase()->setX(newX);
}

void CapteurDecorateur::setY(int newY) {
  this->getBase()->setY(newY);
}

void CapteurDecorateur::setVitesse(double newVitesse) {
  this->getBase()->setVitesse(newVitesse);
}

void CapteurDecorateur::setOrientation(double newOrientation) {
  this->getBase()->setOrientation(newOrientation);
}

void CapteurDecorateur::setAge(int newAge) {
  this->getBase()->setAge(newAge);
}

void CapteurDecorateur::draw(UImg& support) {
  this->getBase()->draw(support);
}

double CapteurDecorateur::getVitesse() const {
  return this->getBase()->getVitesse();
}

double CapteurDecorateur::getCamouflage() const {
  return this->getBase()->getCamouflage();
}

ConcreteBestiole* CapteurDecorateur::getBase() const {
  return this->base;
}

unsigned char* CapteurDecorateur::getLightColor() const { // Renvoie une couleur entre le blanc/gris et al couleur de la bestiole
  unsigned char * col = (unsigned char*) this->couleur;
  col[0] = 3*col[0]/5 + 60;
  col[1] = 3*col[1]/5 + 60;
  col[2] = 3*col[2]/5 + 60;
  return col;
}

unsigned char * CapteurDecorateur::getColor() const {
  return this->getBase()->getColor();
}


CapteurDecorateur::~AccessoireDecorateur() {
    delete base;
}

std::string CapteurDecorateur::getName(){
    return this->name;
}



int CapteurDecorateur::getIdentite() const {
  return this->getBase()->getIdentite();
}

int CapteurDecorateur::getX() const {
  return this->getBase()->getX();
}

int CapteurDecorateur::getY() const {
  return this->getBase()->getY();
}

double CapteurDecorateur::getOrientation() const {
  return this->getBase()->getOrientation();
}

int CapteurDecorateur::getAgeMax() const {
  return this->getBase()->getAgeMax();
}

int CapteurDecorateur::getAge() const {
  return this->getBase()->getAge();
}
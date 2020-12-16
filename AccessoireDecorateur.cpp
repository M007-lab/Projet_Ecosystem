#include "AccessoireDecorateur.h"

// ConcreteBestiole* AccessoireAccessoireDecorateur::getBase() const{
//     return this->base;
// }

// std::string AccessoireAccessoireDecorateur::getName() const{
//     return this->name;
// }
Comportement* AccessoireDecorateur::getComportement() const
{
    return this->getBase()->getComportement();
}
bool AccessoireDecorateur::jeTeVois(const Bestiole & autre) const {
  return this->getBase()->jeTeVois(autre);
}

void AccessoireDecorateur::collide(Bestiole& bestiole)
{
    this->getBase()->collide(bestiole);
}


void AccessoireDecorateur::setX(int newX) {
  this->getBase()->setX(newX);
}

void AccessoireDecorateur::setY(int newY) {
  this->getBase()->setY(newY);
}

void AccessoireDecorateur::setVitesse(double newVitesse) {
  this->getBase()->setVitesse(newVitesse);
}

void AccessoireDecorateur::setOrientation(double newOrientation) {
  this->getBase()->setOrientation(newOrientation);
}

void AccessoireDecorateur::setAge(int newAge) {
  this->getBase()->setAge(newAge);
}

void AccessoireDecorateur::draw(UImg& support) {
  this->getBase()->draw(support);
}

double AccessoireDecorateur::getVitesse() const {
  return this->getBase()->getVitesse();
}

double AccessoireDecorateur::getCamouflage() const {
  return this->getBase()->getCamouflage();
}

ConcreteBestiole* AccessoireDecorateur::getBase() const {
  return this->base;
}

unsigned char* AccessoireDecorateur::getLightColor() const { // Renvoie une couleur entre le blanc/gris et al couleur de la bestiole
  unsigned char * col = (unsigned char*) this->couleur;
  col[0] = 3*col[0]/5 + 60;
  col[1] = 3*col[1]/5 + 60;
  col[2] = 3*col[2]/5 + 60;
  return col;
}

unsigned char * AccessoireDecorateur::getColor() const {
  return this->getBase()->getColor();
}


AccessoireDecorateur::~AccessoireDecorateur() {
    delete base;
}


Comportement* AccessoireDecorateur::getComportement() const
{
    return this->getBase()->getComportement();
}

std::string AccessoireDecorateur::getName(){
    return this->name;
}



int AccessoireDecorateur::getIdentite() const {
  return this->getBase()->getIdentite();
}

int AccessoireDecorateur::getX() const {
  return this->getBase()->getX();
}

int AccessoireDecorateur::getY() const {
  return this->getBase()->getY();
}

double AccessoireDecorateur::getOrientation() const {
  return this->getBase()->getOrientation();
}

int AccessoireDecorateur::getAgeMax() const {
  return this->getBase()->getAgeMax();
}

int AccessoireDecorateur::getAge() const {
  return this->getBase()->getAge();
}
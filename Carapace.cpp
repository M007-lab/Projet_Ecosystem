#include "Carapace.h"

Carapace::Carapace(ConcreteBestiole* base, double coefMort, double coefVitesse) {
    this->name = "Carapace";
    this->base = base;
    this->coefCarapaceVitesse = coefVitesse;
    this->coefCarapaceMort = coefMort;
}

double Carapace::getProbaMort()  const {
    return (1/this->coefCarapaceMort) * (this->getBase()->getProbaMort());
}

double Carapace::getVitesse() const {
  return (1/this->coefCarapaceVitesse) * (this->getBase()->getVitesse());
}

void Carapace::toString(std::ostringstream stream) {
    
    stream << this ;
    // std::string str =  stream.str();
}

void Carapace::draw(UImg& support) {
    this->getBase()->draw(support);
    unsigned char col[3];
    col[0] = 0;
    col[1] = 0;
    col[2] = 0;
    // Dessine un cercle noir autour de la besitole
    support.draw_circle(this->getX(),this->getY(),Config::getInstance()->rayon + 1, col, 1.0f, 0xFFFFFFFF);
    support.draw_circle(this->getX(),this->getY(),Config::getInstance()->rayon + 2, col, 1.0f, 0xFFFFFFFF);
    support.draw_circle(this->getX(),this->getY(),Config::getInstance()->rayon + 3, col, 1.0f, 0xFFFFFFFF);
}

std::ostream& operator<<(std::ostream& flot , const Carapace& carapace) {
    flot << carapace.getBase() << "," << carapace.getName() << "," << carapace.coefCarapaceMort << "," << carapace.coefCarapaceVitesse << "\n";
    return flot ;
}


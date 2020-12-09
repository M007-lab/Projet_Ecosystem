#include "Nageoire.h"

Nageoire::Nageoire(Bestiole* base, double coefVitesse) {
    this->name = "Nageoire";
    this->base = base;
    this->coefNageoire = coefVitesse;
}

double Nageoire::getVitesse() const {
    return this->coefNageoire * (this->getBase()->getVitesse());
}

void Nageoire::toString(std::ostringstream stream) {
    // std::ostringstream stream;
    stream << this ;
    //std::string str =  stream.str();;
}

void Nageoire::draw(UImg& support) {
    this->getBase()->draw(support);

    double xt = (double) this->getX() - cos(this->getOrientation())*Config::getInstance()->rayon*1.5;
    double yt = (double) this->getY() + sin(this->getOrientation())*Config::getInstance()->rayon*1.5;
    int x0 = xt;
    int y0 = yt;
    int x1 = xt - cos(this->getOrientation()+M_PI/3)*Config::getInstance()->rayon*1.5;
    int x2 = xt - cos(this->getOrientation()-M_PI/3)*Config::getInstance()->rayon*1.5;
    int y1 = yt + sin(this->getOrientation()+M_PI/3)*Config::getInstance()->rayon*1.5;
    int y2 = yt + sin(this->getOrientation()-M_PI/3)*Config::getInstance()->rayon*1.5;
    support.draw_triangle(x0, y0, x1, y1, x2, y2, this->getColor());
    // Dessine une petite nageoire a l'arriere du la bestiole
}

std::ostream& operator<<(std::ostream& flot , const Nageoire& nageoire) {
    flot << nageoire.getBase() << "," << nageoire.getName() << "," << nageoire.coefNageoire << "\n";
    return flot ;
}
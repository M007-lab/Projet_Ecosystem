#include "Carapace.h"


Carapace::Carapace(Bestiole* base, double coefMort, double coefVitesse) {
    this->name = "Carapace";
    this->base = base;
    this->coefCarapaceVitesse = coefVitesse;
    this->coefCarapaceMort = coefMort;
    this->accessoiresDecorateurs.push_back(this);
}

double Carapace::getVitesse() const {
  return (1/this->coefCarapaceVitesse) * (this->getBase()->getVitesse());
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
    int y2 = yt + sin(this->getOrientation()-M_PI/3)*Config::getInstance()->rayon*1.5; /
    support.draw_triangle(x0, y0, x1, y1, x2, y2, this->getColor());
}


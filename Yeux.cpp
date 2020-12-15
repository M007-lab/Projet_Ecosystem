#include "Yeux.h"

Yeux::Yeux(ConcreteBestiole* base, double detec, double dist, double angle) {
    this->name = "Yeux";
    this->base = base;
    this->capaciteDetection = detec;
    this->angle = angle;
    this->distance = dist;
}

ConcreteBestiole* Yeux::getBase() const{return base;}
std::string Yeux::getName() const{return name;}

ConcreteBestiole* Yeux::clone()
{
    ConcreteBestiole* ptr = new Yeux(this->getBase()->clone(),this->capaciteDetection,this->distance,this->angle);
    return ptr;
}
bool Yeux::jeTeVois(const Bestiole & autre) const {
    bool voisOk = this->capaciteDetection > autre.getCamouflage();
    bool distanceOk = this->dansDistanceDetection(autre,distance);
    bool champOk = this->dansChampsAngulaire(autre,angle);
    return ( (voisOk && distanceOk && champOk) || this->getBase()->jeTeVois(autre));
}

void Yeux::toString(std::ostringstream stream) {
    
    stream << this ;
    // std::string str =  stream.str();
}

void Yeux::draw(UImg& support) {
    double angleMin = this->getOrientation() - this->angle/2;
    double angleMax = this->getOrientation() + this->angle/2;
    int x1 = this->getX() + this->distance * cos(angleMin);
    int y1 = this->getY() - this->distance * sin(angleMin);
    int x2 = this->getX() + this->distance * cos(angleMax);
    int y2 = this->getY() - this->distance * sin(angleMax);
    support.draw_line(this->getX(), this->getY(), x1, y1, this->getColor());
    support.draw_line(this->getX(), this->getY(), x2, y2, this->getColor());
    // Dessine deux lignes représentant le cone de vision
    this->getBase()->draw(support);
}

std::ostream& operator<<(std::ostream& flot , const Yeux& yeux) {
    flot << yeux.getBase() << "," << yeux.getName() << "," << yeux.distance << "," << yeux.angle << "," << yeux.capaciteDetection << "\n";
    return flot ;
}


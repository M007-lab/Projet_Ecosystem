#include "Oreille.h"


Oreille::Oreille(ConcreteBestiole* base, double detec, double dist) {
    this->name = "Oreille";
    this->base = base;
    this->capaciteDetection = detec;
    this->distance = dist;
    
}
ConcreteBestiole* Oreille::getBase() const{return base;}
std::string Oreille::getName() const{return name;}
void Oreille::toString(std::ofstream& stream) {
    // std::ofstream& stream;
    stream  << this ;
    //std::string str =  stream.str();
}

bool Oreille::jeTeVois(const Bestiole & b) const {
    bool entendOk = this->capaciteDetection > b.getCamouflage();
    bool distanceOk = this->dansDistanceDetection(b, this->distance);
    return ( (entendOk && distanceOk) || this->getBase()->jeTeVois(b));
}

ConcreteBestiole* Oreille::clone() {
  return new Oreille(this->getBase()->clone(), this->capaciteDetection, this->distance);
}
void Oreille::draw(UImg& support) {
    support.draw_circle(this->getX(),this->getY(), this->distance,this->getColor(), 1.0f, 0xFFFFFFFF); // Dessine un cerle représentant le rayon d'écoute de la bestiole
    this->getBase()->draw(support);
}

std::ostream& operator<<(std::ostream& flot , const Oreille& oreille) {
    flot << oreille.getVitesse() << "," << oreille.getName() << "," << oreille.distance << "," << oreille.capaciteDetection << "\n";
    return flot ;
}



#include "Oreille.h"

Oreille::Oreille(Bestiole* base, double detec, double dist) {
    this->name = "Oreille";
    this->base = base;
    this->capaciteDetection = detec;
    this->angle = 360;
    this->distance = dist;
    this->capteurDecorateurs.push_back(this);
}


bool Oreille::jeTeVois(const Bestiole & autre) const {
    bool jeVois = autre.getCamouflage() < this->capaciteDetection;
    bool distanceOk = this->plusProcheQue(autre, this->distance);
    return ( (jeVois && distanceOk) || this->getBase()->jeTeVois(autre));
}


void Oreille::draw(UImg& support) {
    support.draw_circle(this->getX(),this->getY(),this->distance,this->getColor(), 1.0f, 0xFFFFFFFF); // Dessine un cerle représentant le rayon d'écoute de la bestiole
    this->getBase()->draw(support);
}

bool Oreille::isOreille(CapteurDecorateur *capDec) {
    return instanceof<Oreille*>(capDec);
}

Oreille* Oreille::castOreille(CapteurDecorateur *capDec){
    Oreille* oreille = dynamic_cast<Oreille*>(capDec) ;
    return oreille;
}

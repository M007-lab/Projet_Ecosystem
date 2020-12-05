
#include "Gregaire.h"
#include <cmath>

void Gregaire::executeBehavior(Bestiole* bestiole) override{
    double directMoyenne;
    double vitesse = bestiole->getVitesse();
    std::list<Bestiole*> voisins = bestiole->getVoisins();
     

    //calcul de l'direction moyenne des bestioles voisines
    if(voisins.size()!=0) {
        directMoyenne = 0;
        for (auto b : voisins) {
            directMoyenne += b->getDirection();
        }
        directMoyenne /= voisins.size();
    }
    //si elle a pas de voisins, la direction reste la même
    else{
        directMoyenne = bestiole->getDirection();
    }
    
    bestiole->setDirection(directMoyenne);
}

Comportement* Gregaire::dupliquer() const override{
    return new Gregaire(*this);
}

Gregaire::~Gregaire(){

}

std::string Gregaire::getName() override{
    return "Grégaire";
}
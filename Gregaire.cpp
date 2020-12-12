
#include "Gregaire.h"
#include <cmath>

void Gregaire::executeBehavior(Bestiole* bestiole) override{
    double directionMoyenne;
    double vitesse = bestiole->getVitesse();
    std::list<Bestiole*> voisins = bestiole->getVoisins();
     

    //calcul de l'direction moyenne des bestioles voisines
    if(voisins.size()!=0) {
        directionMoyenne = 0;
        for (auto b : voisins) {
            directionMoyenne += b->getDirection();
        }
        directionMoyenne /= voisins.size();
    }
    //si elle a pas de voisins, la direction reste la même
    else{
        directionMoyenne = bestiole->getDirection();
    }
    
    bestiole->setDirection(directionMoyenne);
}

Comportement* Gregaire::dupliquer() const {
    return new Gregaire(*this);
}

Gregaire::~Gregaire(){

}

std::string Gregaire::getName() 
{
    return "Grégaire";
}
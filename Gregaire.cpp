
#include "Gregaire.h"
#include <cmath>

void Gregaire::executeBehavior(Bestiole* bestiole,std::list<Bestiole*> voisins) {
   
    double directionMoyenne;
    // double vitesse = bestiole->getVitesse();
     
    //calcul de l'direction moyenne des bestioles voisines
    if(voisins.size()!=0) {
        directionMoyenne = 0;
        for (auto b : voisins) {
            directionMoyenne += b->getOrientation();
        }
        directionMoyenne /= voisins.size();
    }
    //si elle a pas de voisins, la direction reste la même
    else{
        directionMoyenne = bestiole->getOrientation();
    }
    
    bestiole->setOrientation(directionMoyenne);
}

Gregaire* Gregaire::dupliquer() const {
    return new Gregaire(*this);
}

Gregaire::~Gregaire(){

}

std::string Gregaire::getName() 
{
    return "Grégaire";
}
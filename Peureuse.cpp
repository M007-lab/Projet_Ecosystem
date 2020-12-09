#include "Peureuse.h"
#include <cmath>

void Peureuse::executeBehavior(Bestiole* bestiole, Milieu& milieu){
    std::list<Bestiole*> voisins = bestiole->getVoisins(milieu);
    if(voisins.size()>((Config::getInstance()->seuilPeureuse)){
            directionMoyenne = 0;
            for (auto b : voisins) {
                directionMoyenne += b->getOrientation();
            }
            directionMoyenne /= voisins.size();

            bestiole->setOrientation(-directionMoyenne)
    }
}


Peureuse::~Peureuse(){

}


Peureuse* Peureuse::dupliquer() const{
    return new Peureuse(*this);
}

std::string Peureuse::getName(){
    return "Peureuse";
}
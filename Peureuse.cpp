#include "Peureuse.h"
#include <cmath>

void Peureuse::executeBehavior(Bestiole* bestiole) override{
    std::list<Bestiole*> voisins = bestiole->getVoisins();
    if(voisins.size()>((Config::getInstance()->seuilPeureuse)){
            directionMoyenne = 0;
            for (auto b : voisins) {
                directionMoyenne += b->getDirection();
            }
            directionMoyenne /= voisins.size();

            bestiole->setDirection(-directionMoyenne)
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
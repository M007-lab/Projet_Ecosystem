#include "Peureuse.h"
#include <cmath>

void Peureuse::executeBehavior(Bestiole* bestiole) override{
    std::list<Bestiole*> voisins = bestiole->getVoisins();
    if(voisins.size()>((Config::getInstance()->seuilPeureuse)){
            directMoyenne = 0;
            for (auto b : voisins) {
                directMoyenne += b->getDirection();
            }
            directMoyenne /= voisins.size();

            bestiole->setDirection(-directMoyenne)
    }
}

Peureuse* Peureuse::dupliquer() const{
    return new Peureuse(*this);
}

std::string Peureuse::getName(){
    return "Peureuse";
}
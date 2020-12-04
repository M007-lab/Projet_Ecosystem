#include "Kamikaze.h"
#include <cmath>

void Kamikaze::executeBehavior(Bestiole* bestiole) override{
    double distanceMin = 9999999;
    double vitesse = bestiole->getVitesse();
    std::list<Bestiole*> voisins = bestiole->getVoisins();
    double x = bestiole->getX();
    double y = bestiole->getY();
    double xCible;
    double yCible;
    
    //on calcule le voisin le plus proche
    for (auto b : voisins){
        double xVoisin = b->getX();
        double yVoisin = b->getY();
        double distance = std::sqrt(pow(x-xVoisin, 2) + pow(y-yVoisin, 2));
        if(distance < distanceMin){
            distanceMin = distance;
            xCible=b->getX();
            yCible=b->getY();
        }
    }
    //on s'oriente vers la cible
    if(voisins.size() != 0) {
        xCible -= x;
        yCible -= y;
        direction = -atan2(yCible, xCible);
    }
    //on avance vers la bestiole la plus proche
    x+=std::round(vitesse*cos(direction));
    y-=std::round(vitesse*sin(direction));

    bestiole->setX(x);
    bestiole->setY(y);
    bestiole->setDirection(direction);
}

Kamikaze* Kamikaze::dupliquer() const{
    return new Kamikaze(*this);
}

std::string Kamikaze::getName(){
    return "Kamikaze";
}
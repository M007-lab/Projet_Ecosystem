#include "Kamikaze.h"
#include <cmath>

void Kamikaze::executeBehavior(Bestiole* bestiole, std::list<Bestiole*> voisins) {
    double distanceMin = 9999999;
    double vitesse = bestiole->getVitesse();
    // std::list<Bestiole*> voisins = bestiole->getVoisins(milieu);
    double x = bestiole->getX();
    double y = bestiole->getY();
    double direction;
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
    if(voisins.size() != 0){
        //the principal value of the arc tangent of y/x, expressed in radians.
        direction = atan2(yCible-y, xCible-x);
        bestiole->setOrientation(direction);
    }
}

Kamikaze::~Kamikaze(){

}

Kamikaze* Kamikaze::dupliquer() const {
    return new Kamikaze(*this);
}

std::string Kamikaze::getName() {
    return "Kamikaze";
}
#include "Prevoyante.h"
#include <cmath>

#define PI 3.14159265359


void Prevoyante::executeBehavior(Bestiole* bestiole) override{
    double directionInitiale = bestiole->getDirection();
    double step = 2 * PI / 100;
    std::list<Bestiole*> voisins = bestiole->getVoisins();

    double getMesurePrincipale(double angle){
        while(angle > 2*PI){
            angle -= 2*PI;
        }

        while(angle < 0){           
            angle += 2*PI;          
        }

        return angle;
    }

    bool isSameOrientation(double directionTest, Bestiole* bestioleVoisine) {
        directionVoisin = bestioleVoisine->getDirection();
        return (directionVoisin == directionTest) || (directionVoisin == getMesurePrincipale(directionTest + PI));
    }
    //test 100 orientations
    for(int k=0, k<=100, k++){
        double directionTest = directionInitiale + k * step;
        //mesure principale
        directionTest = getMesurePrincipale(directionTest);

        //marche pas
        if std::any_of(voisins.begin(), voisins.end(), isSameOrientation){
            continue;
        }
        else{
            bestiole->setDirection(directionTest);
            break; 
        }

    }
}

Prevoyante* Prevoyante::dupliquer() const{
    return new Prevoyante(*this);
}

std::string Prevoyante::getName(){
    return "Prévoyante";
}

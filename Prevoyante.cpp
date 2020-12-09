#include "Prevoyante.h"
#include <cmath>

#define PI 3.14159265359


void Prevoyante::executeBehavior(Bestiole* bestiole) override{
    double orientationInitiale;
    double step = 2 * PI / 100;
    //test 100 orientations
    for(int k=0, k<=100, k++){
        double orientationTest = orientationInitiale + k * step;
        //mesure principale
        while(orientation>2*PI){
            orientation-=2*PI;
        }

        while(orientation<0){           
            orientation+=2*PI;          
        }
}

Prevoyante* Prevoyante::dupliquer() const{
    return new Prevoyante(*this);
}

std::string Prevoyante::getName(){
    return "Prévoyante";
}

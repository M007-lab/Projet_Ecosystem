#include "Prevoyante.h"
#include <cmath>

#define PI 3.14159265359


void Prevoyante::executeBehavior(Bestiole* bestiole, std::list<Bestiole*> voisins) {
    double directionInitiale = bestiole->getOrientation();
    double step = 2 * PI / 100;
    // std::list<Bestiole*> voisins = bestiole->getVoisins(milieu);

    
    //test 100 orientations
    // for(int k=0; k<=100; k++){
    //     double directionTest = directionInitiale + k * step;
    //     //mesure principale
    //     // directionTest = getMesurePrincipale(directionTest);

    //     //marche pas
    //     // if (std::any_of(voisins.begin(), voisins.end(), isSameOrientation(directionTest,bestioleVoisine) ){
    //     //     continue;
    //     // }
    //     // else{
    //     //     bestiole->setOrientation(directionTest);
    //     //     break; 
    //     // }

    // }
}

// auto getMesurePrincipale(double angle){
//         while(angle > 2*PI){
//             angle -= 2*PI;
//         }

//         while(angle < 0){           
//             angle += 2*PI;          
//         }

//         return angle;
// };

// auto isSameDirection(double directionTest, Bestiole* bestioleVoisine) {
//     double directionVoisin = bestioleVoisine->getOrientation();
//     return (directionVoisin == directionTest) || (directionVoisin == getMesurePrincipale(directionTest + PI) );
// };
// double Prevoyante::getMesurePrincipale(double direction)
// {

// }

Prevoyante::~Prevoyante(){

}

Prevoyante* Prevoyante::dupliquer() const{
    return new Prevoyante(*this);
}

std::string Prevoyante::getName(){
    return "Prévoyante";
}

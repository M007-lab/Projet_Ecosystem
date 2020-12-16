


#include "FactoryBestiole.h"
#include "Camouflage.h"

#include <iostream>

// std::list<ConcreteBestiole*> updateList(int testNb, std::list<ConcreteBestiole*> bestioles,FactoryBestiole  * creator) {

//   unsigned char col[3] = {255, 0, 255};
//   ConcreteBestiole* newBestiole = creator->createBestiole(new Gregaire,col);
//   // Décoration de la bestiole
//   newBestiole->setAge(10);
//   bestioles.push_back(newBestiole);
//   switch(testNb) {
//     case 0 : // Test le changement de vitesse de Nageoire
//       ConcreteBestiole* clone = newBestiole->cloner();
//       bestioles.push_back(clone);
//       break;
//     }
//   return bestioles;
// }

// bool resultatAttendu(int testNb, std::list<ConcreteBestiole*> listeBestioles) {
//   switch(testNb) {
//     case 0: {
//       double v0 = listeBestioles.front()->getVitesse();
//       double v1 = listeBestioles.back()->getVitesse();
//       int age0 = listeBestioles.front()->getAge();
//       int age1 = listeBestioles.back()->getAge();
//       int ageMax0 = listeBestioles.front()->getAgeMax();
//       int ageMax1 = listeBestioles.back()->getAgeMax();
//       double camouflage0 = listeBestioles.front()->getCamouflage();
//       double camouflage1 = listeBestioles.back()->getCamouflage();
//       unsigned char* color0 = listeBestioles.front()->getColor();
//       unsigned char* color1 = listeBestioles.back()->getColor();
//       Comportement* c0 = listeBestioles.front()->getComportement();
//       Comportement* c1 = listeBestioles.back()->getComportement();
//       return (v1 == v0)&&(age0 == age1)&&(ageMax0 == ageMax1)&&(camouflage0 == camouflage1)&&(color0[0] == color1[0])&&(color0[1] == color1[1])&&(color0[2] == color1[2])&&(typeid(*c0).name()==typeid(*c1).name());
//     }
//   }
//   return false;
// }

int main(int argc, char* argv[]) {
  
      FactoryBestiole* creator = new FactoryBestiole();
      unsigned char col[3] = {255, 0, 255};
      ConcreteBestiole* newBestiole = creator->createBestiole(new Kamikaze,col);
      ConcreteBestiole* CamoufB = new Camouflage(newBestiole,10);
      
      newBestiole->toString();
      CamoufB->toString();
      // std::cout << "age = " << age0 << " ageMax = " << ageMax0 << "Vitesse = "<<v0
      // <<" Camouflage = " <<camouflage0 << "color = "<<color0 << "Comportement = "<< c0 << endl;

      // (v1 == v0)&&(age0 == age1)&&(ageMax0 == ageMax1)&&(camouflage0 == camouflage1)&&(color0[0] == color1[0])&&(color0[1] == color1[1])&&(color0[2] == color1[2])&&(typeid(*c0).name()==typeid(*c1).name());
    delete creator;
    delete newBestiole;
    delete CamoufB;
   
   
}

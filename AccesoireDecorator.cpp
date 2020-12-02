  
#include "AccesoireDecorateur.h"




Bestiole* AccesoireDecorateur::getBase() const {
  return this->base;
}

unsigned char* AccesoireDecorateur::getLightColor() const { // Renvoie une couleur entre le blanc/gris et la couleur de la bestiole
  unsigned char * col = (unsigned char*) this->color;
  col[0] = 3*col[0]/5 + 60;
  col[1] = 3*col[1]/5 + 60;
  col[2] = 3*col[2]/5 + 60;
  return col;
}

// unsigned char * AccesoireDecorateur::getColor() const {
//   return this->getBase()->getColor();
// }


AccesoireDecorateur::~AccesoireDecorateur() {
    delete base;
}



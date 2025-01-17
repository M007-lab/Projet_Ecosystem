#ifndef _AQUARIUM_H_
#define _AQUARIUM_H_

#include "Configuration.h"
#include "Milieu.h"
#include "Bestiole.h"
#include <iostream>
#include "CImg.h"

using namespace std;
using namespace cimg_library;


// class Milieu;


class Aquarium : public CImgDisplay
{

private :
   Milieu       * flotte;

   int            delay;

public :
   Aquarium( int width, int height, int _delay );
   ~Aquarium( void );

   Milieu & getMilieu( void ) { return *flotte; }
   void report(void);
   void run( void );

};


#endif

#include "Aquarium.h"
#include "Milieu.h"
#include "Configuration.h"
#include "FactoryBestiole.h"
#include "AccessoireDecorateur.h"
#include "CapteurDecorateur.h"
#include <iostream>

using namespace std;


int main(int argc, char *argv[])
{
   Config::filename = argv[1];
   Aquarium       ecosysteme( 980, 640, 30 );

   // for ( int i = 1; i <= 20; ++i )
   //    ecosysteme.getMilieu().addMember( Bestiole() );
   ecosysteme.run();


   return 0;

}

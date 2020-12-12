#include "Aquarium.h"

#include "Milieu.h"

#include <iostream>
#include <iomanip>
#include <ctime>

Aquarium::Aquarium( int width, int height, int _delay ) : CImgDisplay(), delay( _delay )
{

   int         screenWidth = 1280; //screen_width();
   int         screenHeight = 1024; //screen_height();


   cout << "const Aquarium" << endl;

   flotte = new Milieu( width, height );
   assign( *flotte, "Simulation d'ecosysteme" );

   move( static_cast<int>((screenWidth-width)/2), static_cast<int>((screenHeight-height)/2) );

}


Aquarium::~Aquarium( void )
{
   report();
   delete flotte;
   cout << "dest Aquarium" << endl;

}

void Aquarium::report()
{
   std::stringstream filename;
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
   filename << "Rapport_Simulation_" <<std::put_time(&tm, "%d-%m-%Y %H-%M-%S")  << ".txt";
   std::ofstream myfile;
   myfile.open(filename.str());
   flotte->report(myfile);
}
void Aquarium::run( void )
{

   cout << "running Aquarium" << endl;

   while ( ! is_closed() )
   {

      // cout << "iteration de la simulation" << endl;

      if ( is_key() ) {
         cout << "Vous avez presse la touche " << static_cast<unsigned char>( key() );
         cout << " (" << key() << ")" << endl;
         if ( is_keyESC() ) close();
      }
     if(button()&1){
          flotte->killBestiole(mouse_x(),mouse_y());
      }
      flotte->step();
      display( *flotte );

      wait( delay );

   } // while

}

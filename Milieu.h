#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"
#include "Createur.h"

#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Milieu : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   std::vector<Bestiole>   listeBestioles;
   // Initialisation des comportements
   std::vector<Comportement *> listeComportements = {new Gregaire,new Kamikaze, new Peureuse,new Prevoyante,new Multiple};
   std::map<Comportement*,Color> mapComportementCouleur;
   std::map<Comportement*, double> mapComportementPct;
   Createur * creator ;

public :
   Milieu( int _width, int _height );
   ~Milieu( void );
   
   int getWidth( void ) const;
   int getHeight( void ) const;
   std::vector<Bestiole> getListeBestioles() const;
   void init_population();
   void step( void );
   
   void newBestiole();
   void addBestiole( const Bestiole & b );
   void killBestiole();
   void checkInput();
   int nbVoisins( const Bestiole & b );

};


#endif

#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"
#include "CreateurBestiole.h"
// #include "Createur.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Color
{
public :
    unsigned char color[3];
    Color(){};
    Color(char r,char g,char b)
    {
        color[0] = r;
        color[1] = g;
        color[2] = b;
    };
    Color(const Color& c)
    {
        color[0] = c.color[0];
        color[1] = c.color[1];
        color[2] = c.color[2];
    };
};

class Milieu : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   // std::vector<Bestiole*>   listeBestioles;
   std::map<int,Bestiole *> idToBestioles;
   // Initialisation colors
   Color purple  = Color(255,0,255);
   Color red    = Color(255,0,0);
   Color green  = Color(0,255,0);
   Color blue   = Color(0,0,255);
   Color yellow = Color(255,255,0);
   // Initialisation des comportements
   std::vector<Comportement *> listeComportements;
   std::map<Comportement*,Color> mapComportementColor;
   std::map<Comportement*, double> mapComportementWeight;
   CreateurBestiole creator = CreateurBestiole() ;

public :
   Milieu( int _width, int _height );
   ~Milieu( void );
   
   int getWidth( void ) const;
   int getHeight( void ) const;
   // std::vector<Bestiole*> getListeBestioles() const;

   void init_population();
   void step( void );
   void newBestiole();
   void addBestiole(Bestiole * b );
   void killBestiole(int id);
   void killBestiole(int x, int y); // input mouse killing
   std::list<Bestiole*> getBestiolesList(); // return new Liste Bestiole after killing expired ones
   int  nbVoisins( const Bestiole & b );
   void report(std::ofstream &file);

};


#endif

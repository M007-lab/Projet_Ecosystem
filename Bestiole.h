#ifndef _BESTIOLE_H_
#define _BESTIOLE_H_


#include "UImg.h"
#include "Milieu.h"

#include <list>
#include <iostream>

using namespace std;



class Comportement;

class Bestiole
{

private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;

   static int              next;

protected :
   int               identite;
   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;
   double            age;
   double            ageMax;
   T               * couleur ;
   

public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   Bestiole(int x,int y,int ageMax,int vitesse,int orientation);
   ~Bestiole( void );                              // Destructeur
   virtual Bestiole* action(std::list<Bestiole*> allBestioles);
   void bouge( int xLim, int yLim );
   virtual void draw( UImg & support ) = 0;
   virtual void toString(iostream & out) = 0;
   virtual void toString() ;
   virtual bool jeTeVois( const Bestiole & b ) const = 0;
   virtual void collide(); // Collision between Bestioles
   virtual Bestiole* checkClone();
   virtual Bestiole* clone() = 0;



   // Setters
   virtual void setX(int newX) = 0 ;
   virtual void setY(int newY) = 0;
   virtual void setVitesse(double newVitesse) = 0 ;
   virtual void setOrientation(double newOrientation) = 0 ;
   virtual void setAge(int newAge) = 0 ;

   //getters
   virtual int getX() const;
   virtual int getY() const;
   virtual int getIdentite() const;
   virtual int getAge() const;
   virtual int getAgeMax() const;
   virtual double getVitesse() const;
   virtual double getOrientation() const;
   void initCoords( int xLim, int yLim );
   virtual double getProbaMort() const; // pure virtual method. Bestiole is an abstract class
   virtual double getCamouflage() const;

   virtual unsigned char * getColor() const;
   virtual unsigned char* getLightColor() const;

   virtual double getDistanceA(const Bestiole& b) const;
   virtual bool dansDistanceDetection(const Bestiole & b, double distance) const;
   virtual double between0and2PI(double angle) const;
   virtual bool dansChampsAngulaire(const Bestiole & b, double champ) const;

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

};


#endif

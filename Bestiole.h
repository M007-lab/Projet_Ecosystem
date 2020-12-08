#ifndef _BESTIOLE_H_
#define _BESTIOLE_H_


#include "UImg.h"
#include "Comportement.h"
#include "Milieu.h"

#include <list>
#include <iostream>

using namespace std;


class Milieu;


class Bestiole
{

private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;

   static int              next;

private :
   int               identite;
   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;
   double            age;
   

   T               * couleur;

private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   
   Bestiole( void );                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   Bestiole(int x,int y,int ageMax,double vitesse,double orientation);
   ~Bestiole( void );                              // Destructeur
   
   // to override                                              // Operateur d'affectation binaire par defaut
   virtual void action( Milieu & monMilieu ) = 0;
   virtual void draw( UImg & support ) = 0;
   virtual void toString(iostream & out) = 0;
   // virtual bool jeTeVois( const Bestiole & b ) const = 0;
   virtual double getVitesse() const = 0;
   std::list<Bestiole> getVoisins(Milieu & monMilieu);
   void collide(); // Collision between Bestioles
   virtual Bestiole* clone() = 0;
   // virtual Comportement* getComportement() const = 0;

   // Setters
    // standard
   void setX(int newX) ;
   void setY(int newY) ;
   void setVitesse(double newVitesse) ;
   void setOrientation(double newOrientation) ;
   void setAge(int newAge) ;

   //getters
    // standard
   int getX() const;
   int getY() const;
   int getIdentite() const;
   int getAge() const;
   int getAgeMax() const;
   double getVitesse() const;
   double getOrientation() const;
   void initCoords( int xLim, int yLim );
    // to override
   virtual void getDecorateurs(std::list<std::string> &decorateurs) = 0; // to override in Decorator class 
   virtual Comportement* getComportement() const = 0; // pure virtual method. Bestiole is an abstract class
   virtual double getProbaMort() const =0;
   virtual double getVitesseCoeff() const =0;
   virtual double getCamouflage() const = 0;
   

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

};


#endif

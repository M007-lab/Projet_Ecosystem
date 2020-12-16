#ifndef _CONBESTIOLE_H
#define _CONBESTIOLE_H

#include "Bestiole.h"
#include "Comportement.h"
#include "Configuration.h"
#include "RandomUtils.h"




class ConcreteBestiole: public Bestiole {
    
public:
    ConcreteBestiole(){};
    ConcreteBestiole(int _x,int _y, int _ageMax, double _vitesse, double _orientation);
    virtual ~ConcreteBestiole();
    ConcreteBestiole(const ConcreteBestiole& b);
    virtual bool jeTeVois( const Bestiole & b ) const ;
    virtual ConcreteBestiole* clone() = 0;
    virtual Comportement* getComportement() const =0;
    virtual ConcreteBestiole* checkClone();
    virtual void collide(Bestiole& autre);
    virtual ConcreteBestiole* action( std::list<Bestiole*> allBestioles );
    virtual void toString(std::ofstream &) const override;
    virtual void toString() const override;
   
    
    std::list<Bestiole*> getVoisins(std::list<Bestiole*> allBestioles);
    virtual double getCamouflage() const override;
    virtual double getProbaMort() const override;
    virtual void draw(UImg& support) override;
    // virtual void getDecorateurs(std::list<std::string> &decorateurs) override;
   
   // Setters
   virtual void setX(int newX) override;
   virtual void setY(int newY) override;
   virtual void setVitesse(double newVitesse) override;
   virtual void setOrientation(double newOrientation) override;
   virtual void setAge(int newAge) override;

   virtual double getVitesse() const override;

};
#endif
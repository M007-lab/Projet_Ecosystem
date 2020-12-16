#ifndef _CAPTEURDECORATEUR_H
#define _CAPTEURDECORATEUR_H

#include "ConcreteBestiole.h"

class CapteurDecorateur : public ConcreteBestiole {
  protected :
    std::string name;
    ConcreteBestiole* base;

  public :
    virtual ~CapteurDecorateur(){};

    virtual ConcreteBestiole* getBase() const = 0;
    virtual std::string getName() const = 0;
    
    virtual ConcreteBestiole* clone() = 0;
    Comportement* getComportement() const;
    

    virtual void toString(ofstream& stream) = 0;
    virtual void draw(UImg& support) = 0;

    virtual bool jeTeVois(const Bestiole & autre) const override;
    virtual void collide(Bestiole & autre) override;
    virtual double getVitesse() const override;
    virtual double getCamouflage() const override;
    ConcreteBestiole* getBase() const;
    virtual void draw(UImg& support);
    virtual void setX(int newX) override;
    virtual void setY(int newY) override;
    virtual void setVitesse(double newVitesse) override;
    virtual void setOrientation(double newOrientation) override;
    virtual void setAge(int newAge) override;
    virtual ConcreteBestiole* clone() = 0;
    unsigned char* getLightColor() const;
    std::string getName();

};
#endif
#ifndef _ACCESSOIREDECORATEUR_H
#define _ACCESSOIREDECORATEUR_H

#include "ConcreteBestiole.h"

class AccessoireDecorateur : public ConcreteBestiole {
protected :
    std::string name;
    ConcreteBestiole* base;

public :
    virtual ~AccessoireDecorateur(){};

    virtual ConcreteBestiole* getBase() const = 0;
    virtual std::string getName() const = 0;
    
    virtual ConcreteBestiole* clone() = 0;
    Comportement* getComportement() const ;

    virtual double getVitesse() const override = 0 ;
    virtual double getCamouflage() const override = 0 ;
    virtual double getProbaMort() const override  = 0;

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


    // getter
    Comportement* getComportement() const;
    int getIdentite() const override;
    int getX() const override;
    int getY() const override;
    double getOrientation() const override;
    int getAgeMax() const override;
    int getAge() const override;
    unsigned char * getColor() const override;

};
#endif
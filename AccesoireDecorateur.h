// #ifndef _ACCESOIREDECORATEUR_H
// #define _ACCESOIREDECORATEUR_H

#include "Bestiole.h"
#include "Comportement.h"

class AccesoireDecorateur : public Bestiole {
  protected :
    std::string name;
    Bestiole* base;
  public :
    virtual ~AccesoireDecorateur();
    Bestiole* getBase() const;
    virtual void draw(UImg& support);

    // virtual void collisionBestiole() override;
    virtual double getVitesse() const =0;
    virtual double getCamouflage() const=0 ;
    // virtual void setX(int newX) override;
    // virtual void setY(int newY) override;
    // virtual void setVitesse(double newVitesse) override;
    // virtual void setOrientation(double newOrientation) override;
    // virtual void setAge(int newAge) override;
    virtual Bestiole* clone() = 0;
    // unsigned char* getLightColor() const;
    std::string getName();


    // getter
    // Comportement* getComportement() const;
    // int getIdentite() const override;
    // int getPosition() const override;
    // double getOrientation() const override;
    // int getAgeMax() const override;
    // int getAge() const override;
    // unsigned char * getColor() const override;
    virtual void getDecorateurs(std::list<std::string> &decorateurs) override;
};

// #endif
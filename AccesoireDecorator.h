#ifndef ACCESOIREDECORATEUR_H
#define ACCESOIREDECORATEUR_H

#include "Bestiole.h"
#include "Comportement.h"

class AccesoireDecorateur : public Bestiole {
  protected :
    std::string name;
    Bestiole* base;
  public :
    virtual ~AccesoireDecorateur();
    virtual void collisionBestiole() override;
    virtual double getVitesse() const override;
    virtual double getCamouflage() const override;
    EspeceA* getBase() const;
    virtual void draw(UImg& support);
    virtual void setX(int newX) override;
    virtual void setY(int newY) override;
    virtual void setVitesse(double newVitesse) override;
    virtual void setOrientation(double newOrientation) override;
    virtual void setAge(int newAge) override;
    virtual Bestiole* cloner() = 0;
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
    virtual void getDecorateurs(std::list<std::string> &decorateurs) override;
};

#endif
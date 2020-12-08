// #ifndef _ACCESOIREDECORATEUR_H
// #define _ACCESOIREDECORATEUR_H

#include "Bestiole.h"
#include "Comportement.h"

class AccessoireDecorateur : public Bestiole {
protected :
    std::string name;
    Bestiole* base;
    std::list<AccessoireDecorateur> accessoiresDecorateurs;

<<<<<<< HEAD
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
=======
public :
    virtual ~AccessoireDecorateur();
    virtual void draw(UImg& support);
    virtual bool jeTeVois( const Bestiole & b ) const;
>>>>>>> 735f446b4822c7821ee1faedfbde2fc1fee797f7

    Bestiole* getBase() const;
    std::string getName() const;

    std::list<AccessoireDecorateur> getAccessoireDecorateurs() override;
};

#endif
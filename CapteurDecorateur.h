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
    
    virtual bool jeTeVois( const Bestiole & b ) const override = 0;

    virtual void toString(std::ostringstream stream) = 0;
    virtual void draw(UImg& support) = 0;

};
#endif
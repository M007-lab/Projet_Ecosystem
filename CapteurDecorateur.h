#ifndef _CAPTEURDECORATEUR_H
#define _CAPTEURDECORATEUR_H

#include "ConcreteBestiole.h"

class CapteurDecorateur : public ConcreteBestiole {
  protected :
    std::string name;
    ConcreteBestiole* base;

  public :
    virtual ~CapteurDecorateur();

    ConcreteBestiole* getBase() const;
    std::string getName() const;

    virtual bool jeTeVois( const Bestiole & b ) const override = 0;

    virtual void toString(std::ostringstream stream) = 0;
    virtual void draw(UImg& support) = 0;

};
#endif